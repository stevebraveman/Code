#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
namespace STman {
	template <typename Tp>
	inline void read(Tp &x) {
		#define C getchar()
		Tp f = 1;x = 0;
		char k = C;
		while (k < '0' || k > '9') {if (k == '-') f = -1; k = C;}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0'; k = C;}
		x = x * f;
		#undef C
	}
	template <typename Tp>
	inline void write(Tp x) {
		if (x < 0) putchar('-') , x = -x;
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
	template <typename Tp>
	inline Tp max(Tp a, Tp b) {
		if (a > b) return a;
		else return b;
	}
	template <typename Tp>
	inline Tp min(Tp a, Tp b) {
		if (a < b) return a;
		else return b;
	}
	template <typename Tp>
	inline void swap(Tp &a, Tp &b) {
		Tp t = a;
		a = b;
		b = t;
	}
	template <typename Tp>
	inline Tp abs(Tp &a) {
		if (a < 0) return -a;
		else return a;
	}
	inline void sp() {
		putchar(32);
	}
	inline void et() {
		putchar(10);
	}
}
using namespace STman;
struct Edge {
	int v, nx;
}e[MAXN];
int head[MAXN], ecnt, n, t1, t2, a, s[MAXN][2], ans, mtch[MAXN];
int vis[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
bool Hungary(int k, int t) {
	for (int i = head[k]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to] != t) {
			vis[to] = t;
			if (!mtch[to] || Hungary(mtch[to], t)) {
				mtch[to] = k;
				mtch[k] = to;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a);
		t1 = i + a;
		if (t1 > n) t1 -= n;
		t2 = i - a;
		if (t2 < 1) t2 += n;
		if (t1 < t2) {
			s[i][0] = t1, s[i][1] = t2;
		}
		else {
			s[i][0] = t2, s[i][1] = t1;
		}
		add(i, s[i][1] + n);
		add(i, s[i][0] + n);
	}
	for (int i = n; i >= 1; i--) {
		if (Hungary(i, i)) {
			ans++;
		}
	}
	if (ans < n) {
		puts("No Answer");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		write(mtch[i] - n - 1), sp();
	}
	return 0;
}

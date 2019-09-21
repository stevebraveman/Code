#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 40010
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
}e[MAXN * 4];
int head[MAXN], ecnt, mtch[MAXN], op, ans, n, t, vis[MAXN];
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
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	read(t);
	while (t--) {
		read(n);
		ans = 0;
		memset(mtch, 0, sizeof(mtch));
		memset(head, 0, sizeof(head));
		memset(vis, 0, sizeof(vis));
		ecnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				read(op);
				if (op) add(i, j);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (Hungary(i, i)) {
				ans++;
			}
		}
		if (ans == n) {
			puts("Yes");
		}
		else puts("No");
	}
}
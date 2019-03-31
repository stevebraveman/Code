#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAXN 10000002
#define INF 2000000000
namespace STman {
	template <typename Tp>
	inline void read(Tp &x) {
	#define C getchar()
		Tp f = 1;
		x = 0;
		char k = C;
		while (k < '0' || k > '9') {
			if (k == '-') f = -1;
			k = C;
		}
		while (k >= '0' && k <= '9') {
			x = x * 10 + k - '0';
			k = C;
		}
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
	inline Tp max(Tp a , Tp b) {
		if (a > b) return a;
		else return b;
	}
	template <typename Tp>
	inline Tp min(Tp a , Tp b) {
		if (a < b) return a;
		else return b;
	}
	template <typename Tp>
	inline void swap(Tp &a , Tp &b) {
		Tp t = a;
		a = b;
		b = a;
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
int mtch[MAXN], vis[MAXN / 1000 + 10], n, ecnt, ans, x, y, head[MAXN];
struct Edge {
	int v, nx;
}e[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
bool Hungary(int k) {
	if (vis[k]) return 0;
	vis[k] = 1;
	for (int i = head[k]; i; i = e[i].nx) {
		int to = e[i].v;
		if (!mtch[to] || Hungary(mtch[to])) {
			mtch[to] = k;
			return 1;
		}
	}
	return 0;
}
int main() {
	read(n);
	for (int i = 1 ; i <= n ; i++) {
		read(x) , read(y);
		add(x, i), add(y, i);
	}
	for (int i = 1 ; i <= 10000 ; i++) {
		if (Hungary(i)) {
			ans++;
		}
		else break;
		memset(vis , 0 , sizeof(vis));
	}
	write(ans);
	return 0;
}
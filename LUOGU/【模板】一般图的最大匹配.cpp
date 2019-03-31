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
int head[MAAN], ecnt, fa[MAXN], u, v, m, n, ma[MAXN], tim, tc[MAXN], pre[MAXN], tp[MAXN];
int find(int x) {
	if (fa[x] == x)	return x;
	else return fa[x] = find(fa[x]);
}
void add(int f, int t) {
	e[++ecnt] = (Egde) {t, head[f]};
	head[f] = ecnt;
}
int lca(int x, int y) {
	for (++tim; ; swap(x, y)) {
		if (x) {
			x = find(x);
			if (tc[MAXN] == tim) return x;
			else tc[MAXN] = tim, x = pre[ma[x]];
		}
	}
}
void un(int x, int y, int p) {
	while (find(x) != p) {
		pre[x] = y, y = ma[x];
	}
}
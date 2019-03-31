#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define ll long long
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
}e[MAXN * 50];
int head[MAXN], ecnt, root, size[MAXN], dfn[MAXN], tim, low[MAXN], n, m, x, y;
ll ans[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void tarjan(int u) {
	int z = 0;
	size[u] = 1;
	dfn[u] = low[u] = ++tim;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			size[u] += size[v];
			low[u] = min(low[v], low[u]);
			if (dfn[u] <= low[v]) {
				ans[u] += (ll)z * size[v];
				z += size[v];
			}
		}
		else low[u] = min(dfn[v], low[u]);
	}
	ans[u] += (ll)z * (n - z - 1);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(x), read(y);
		add(x, y);
		add(y, x);
	}
	tarjan(1);
	for (int i = 1; i <= n; i++) {
		write((ans[i] + n - 1) << 1), et();
	}
	return 0;
}
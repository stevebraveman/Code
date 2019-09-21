#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
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
int head[MAXN], r, ecnt, x, tim, y, dfn[MAXN], low[MAXN], stack[MAXN], n, m, tot;
bool cut[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	int flag = 0;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				flag++;
				if (u != r || flag > 1) cut[u] = 1;
			}
		}
		else low[u] = min(low[u], dfn[v]);
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(x), read(y);
		if (x == y) continue;
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) r = i, tarjan(i);
	}
	for (int i = 1; i <= n; i++) {
		if (cut[i]) tot++;
	}
	write(tot), et();
	for (int i = 1; i <= n; i++) {
		if (cut[i]) write(i), sp();
	}
}
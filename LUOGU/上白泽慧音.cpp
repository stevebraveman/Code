#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#define MAXN 501000
namespace STman {
	template <typename Tp>
	inline void read(Tp &x) {
		#define C getchar()
		Tp f = 1;x = 0;
		char k = C;
		while (k < '0' || k > '9') {if (k == '-') f = -1;k = C;}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0';k = C;}
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
	inline void sp() {
		printf(" ");
	}
	inline void et() {
		puts("");
	}
}
using namespace STman;
struct Edge {
	int v, nx;
}e[MAXN * 10];
int ecnt, vis[MAXN], num = 0, in[MAXN], n, m, a, b, flag, k, maxn = 0;
int dfn[MAXN], low[MAXN], tim, st[MAXN], hd = 0, head[MAXN], size[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge){t, head[f]};
	head[f] = ecnt;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++hd] = u;
	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[v], low[u]);
		}
		else if (vis[v]) low[u] = min(dfn[v], low[u]);
	}
	if (dfn[u] == low[u]) {
		num++;
		int v;
		do {
			v = st[hd--];
			vis[v] = 0;
			in[v] = num;
			size[num]++;
		} while (v != u);
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(a), read(b), read(flag);
		if (flag == 1) {
			add(a, b);
		}
		if (flag == 2) {
			add(b, a);
			add(a, b);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			tarjan(i);
		}
	}
	for (int i = 1; i <= num; i++) {
		maxn = max(size[i], maxn);
	}
	write(maxn), et();
	for (int i = 1; i <= n; i++) {
		if (size[in[i]] == maxn) {
			write(i), sp();
		}
	}
	return 0;
}
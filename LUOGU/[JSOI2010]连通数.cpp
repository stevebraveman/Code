#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10010
namespace STman {
	inline char gc(){
		#ifdef ONLINE_JUDGE
			static char now[1 << 16], *S, *T;
			if (T == S) {T = (S = now) + fread(now, 1, 1 << 16, stdin); if (T == S) return EOF;}
			return *S++;
		#else 
			return getchar();
		#endif
	}
	template <typename Tp>
	inline void read(Tp &x) {
		Tp f = 1;x = 0;
		char k = gc();
		while (k < '0' || k > '9') {if (k == '-') f = -1;k = gc();}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0';k = gc();}
		x = x * f;
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
}e[MAXN * 100];
int n, m, dfn[MAXN], low[MAXN], num, tim, st[MAXN], top, in[MAXN], si[MAXN], kk;
int x[MAXN], y[MAXN], cnt, tot[MAXN], vis[MAXN], p[MAXN], ans, ecnt, head[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		num++;
		int v;
		do {
			v = st[top--];
			vis[v] = 0;
			in[v] = num;
			si[v]++;
		} while (u != v);
	}
}
void dfs(int u, int t) {
	tot[u] += p[u], vis[u] = t;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to] == t) continue;
		dfs(to, t);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int c;
			scanf("%1d", &c);
			if (c == 1) {
				x[++cnt] = i, y[cnt] = j;
				add(i, j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	memset(head, 0, sizeof(head));
	memset(e, 0, sizeof(e));
	memset(vis, 0, sizeof(vis));
	ecnt = 0;
	for (int i = 1; i <= cnt; i++) {
		if (in[x[i]] != in[y[i]]) {
			add(in[x[i]], in[y[i]]);
		}
	}
	for (int i = 1; i <= n; i++) {
		p[in[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		dfs(in[i], ++kk);
	}
	for (int i = 1; i <= num; i++) {
		ans += tot[i];
	}
	write(ans), et();
}
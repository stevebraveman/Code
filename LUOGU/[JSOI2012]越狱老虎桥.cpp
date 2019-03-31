#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000100
#define ll long long
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
struct Edge {
	int v, nx, w;
}e[MAXN];
int head[MAXN], ecnt, dfn[MAXN], low[MAXN], n, m, x[MAXN], y[MAXN], z[MAXN], tim, st[MAXN], top, g[MAXN], si[MAXN], ans = 0;
int cnte[MAXN];
long long p[MAXN];
int num, br, in[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (fa == v) continue;
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(dfn[v], low[u]);
	}
	if (low[u] == dfn[u]) {
		int v;
		num++;
		do {
			v = st[top--];
			in[v] = num;
			si[num]++;
		} while (u != v);
	}
}
void dfs(int x, int fa) {
	for (int i = head[x]; i; i = e[i].nx) {
		int to = e[i].nx;
		int w = e[i].w;
		ans = max(ans, w);
		dfs(to, x);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x[i], &y[i], &w[i]);
		add(x[i], y[i], 0);
		add(y[i], x[i], 0);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	memset(head, 0, sizeof(head));
	ecnt = 0;
	for (int i = 1; i <= m; i++) {
		if (in[x[i]] != in[y[i]]) {
			add(in[x[i]], in[y[i]], w[i]);
			add(in[y[i]], in[x[i]], w[i]);
			cnte[in[x[i]]]++;
			cnte[in[y[i]]]++;
		}
	}
	dfs(1, 0);
	for (int i = 1; i <= num; i++) {
		if (cnte[i] == 1) {
			ans++;
		}
	}
}
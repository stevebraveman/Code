#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 300010
struct Edge {
	int v, nx;
}e[MAXN << 2];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int head[MAXN], ecnt, n, m, x[MAXN], y[MAXN], dfn[MAXN], low[MAXN];
int tim, st[MAXN], num, in[MAXN], top, dia, dep[MAXN], maxx, r;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (v == fa) continue;
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[v], low[u]);
		}
		else low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		num++;
		int v;
		do {
			v = st[top--];
			in[v] = num;
		} while (u != v);
	}
}
int dfs(int u, int fa) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa) continue;
		dep[to] = dep[u] + 1;
		dfs(to, u);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		add(x[i], y[i]);
		add(y[i], x[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i, i);
	}
	memset(head, 0, sizeof(head));
	ecnt = 0;
	for (int i = 1; i <= m; i++) {
		if (in[x[i]] != in[y[i]]) {
			add(in[x[i]], in[y[i]]);
			add(in[y[i]], in[x[i]]);
		}
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		if (maxx < dep[i]) maxx = dep[i], r = i;
	}
	memset(dep, 0, sizeof(dep));
	dfs(r, 0);
	maxx = 0;
	for (int i = 1; i <= n; i++) {
		if (maxx < dep[i]) maxx = dep[i];
	}
	printf("%d\n", maxx);
}
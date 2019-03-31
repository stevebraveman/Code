#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 100010
#define clr(x) memset(x, 0, sizeof(x))
struct Edge {
	int v, nx;
}e[MAXN << 2];
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int head[MAXN], T, ecnt, n, m, x[MAXN], y[MAXN], dfn[MAXN], ent[MAXN];
int low[MAXN], tim, st[MAXN], top, in[MAXN], siz[MAXN], num, f[MAXN], ans;
bool vis[MAXN];
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
			low[u] = min(low[v], low[u]);
		}
		else if (vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		num++;
		int v;
		do {
			v = st[top--];
			vis[v] = 0;
			in[v] = num;
			siz[num]++;
		} while (u != v);
	}
}
void dfs(int u) {
	if (f[u]) return;
	f[u] = siz[u];
	int kk = 0;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		dfs(to);
		kk = max(kk, f[to]);
	}
	f[u] += kk;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		clr(dfn), clr(low), clr(head), clr(x), clr(y), clr(st);
		top = 0, ecnt = 0, num = 0, ans = 0;
		clr(vis), clr(in), clr(ent), clr(siz), clr(e), clr(f);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &x[i], &y[i]);
			add(x[i], y[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) tarjan(i);
		}
		clr(e);
		clr(head);
		ecnt = 0;
		for (int i = 1; i <= m; i++) {
			if (in[x[i]] != in[y[i]]) {
				add(in[x[i]], in[y[i]]);
			}
		}
		for (int i = 1; i <= num; i++) {
			if (!f[i]) dfs(i);
		}
		for (int i = 1; i <= num; i++) {
			ans = max(ans, f[i]);
		}
		printf("%d\n", ans);
	}
}
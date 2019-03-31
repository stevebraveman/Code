#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 100010
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int f, v, nx;
}e[MAXN], ef[MAXN];
int head[MAXN], ecnt, n, m, dfn[MAXN], low[MAXN], num, tim, top, toe[MAXN];
int in[MAXN], et[MAXN], si[MAXN], x, y, out[MAXN], h[MAXN], ect, st[MAXN];
bool vis[MAXN], vi[MAXN];
double ans = 0.0, pr, luk[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {f, t, head[f]};
	head[f] = ecnt;
}
void add_e(int f, int t) {
	e[++ect] = (Edge) {f, t, h[f]};
	h[f] = ect;
}
struct point {
	int id, to;
}p[MAXN];
bool cmp(point a, point b) {
	return a.to > b.to;
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
		else if (vis[v]) low[u] = min(dfn[v], low[u]);
	}
	if (dfn[u] == low[u]) {
		num++;
		int v;
		do {
			v = st[top--];
			in[v] = num;
			vis[v] = 0;
		} while (u != v);
	}
}
void bfs(int u) {
	std::queue <int> q;
	q.push(u);
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int i = h[k]; i; i = ef[i].nx) {
			int to = ef[i].v;
			if (vi[to]) continue;
			vi[to] = 1;
			toe[u]++;
		}
	}
}
int main() {
	freopen("kill.in", "r", stdin);
	freopen("kill.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	pr = 1.0 / n;
	if (num == 1) {
		printf("%.6f", 1.0 - pr);
		return 0;
	}
	for (int i = 1; i <= ecnt; i++) {
		int u = e[i].f, v = e[i].v;
		if (in[u] != in[v]) {
			add_e(in[u], in[v]);
			et[in[v]]++;
			out[in[u]]++;
		}
	}
	for (int i = 1; i <= num; i++) {
		if (et[i] == 0 && out[i]) bfs(i);
	}
	for (int i = 1; i <= num; i++) {
		if (out[i]) bfs(i);
	}
	for (int i = 1; i <= num; i++) {
		if (toe[i]) {
			ans += pr;
		}
	}
	printf("%.6f", 1.0 - ans);
	return 0;
}
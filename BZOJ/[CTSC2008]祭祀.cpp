#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000100
#define INF 2000000000
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, w;
}e[MAXN];
std::queue <int> q;
int head[MAXN], ecnt = 1, n, m, x, y, dep[MAXN], cur[MAXN], nex[MAXN], r, k, g[210][210];
bool vis[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	while (!q.empty()) q.pop();
	for (int i = 1; i <= n * n + 2; i++) {
		cur[i] = head[i];
	}
	dep[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dep[to] > INF && e[i].w) {
				dep[to] = dep[u] + 1;
				q.push(to);
			}
		}
	}
	if (dep[t] < INF) return 1;
	else return 0;
}
int dfs(int s, int t, int l) {
	if (!l || s == t) {
		return l;
	}
	int fl = 0, f;
	for (int i = cur[s]; i; i = e[i].nx) {
		cur[s] = i;
		int to = e[i].v;
		if (dep[to] == dep[s] + 1 && (f = dfs(to, t, min(l, e[i].w)))) {
			l -= f;
			fl += f;
			e[i].w -= f;
			e[i ^ 1].w += f;
			if (!l) break;
		}
	}
	return fl;
}
int Dinic(int s, int t) {
	int maxf = 0;
	while (bfs(s, t)) {
		maxf += dfs(s, t, INF);
	}
	return maxf;
}
void find(int x) {
	printf("%d ", x);
	vis[x] = true;
	if (nex[x]) find(nex[x]);
}
int main() {
	scanf("%d%d", &n, &m);
	r = n * 2 + 1;
	k = n * 2 + 2;
	for (int i = 1; i <= n; i++) {
		add(r, i, 1);
		add(i + n, k, 1);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		g[x][y] = 1;
	}
	for (int p = 1; p <= n; p++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] |= (g[i][p] & g[p][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (g[i][j]) {
				add(i, j + n, 1);
			}
		}
	}
	add(x, y + n, 1);
	int tot = n - Dinic(r, k);
	printf("%d", tot);
}
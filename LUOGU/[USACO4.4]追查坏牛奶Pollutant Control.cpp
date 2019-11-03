#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1001000
#define INF 2000000000
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
int head[MAXN], ecnt = 1, n, m, x[MAXN], y[MAXN], dep[MAXN], cur[MAXN], z;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
bool bfs(int s, int t) {
	for (int i = 1; i <= n; i++) {
		cur[i] = head[i];
		dep[i] = 0x7fffffff;
	}
	std::queue <int> q;
	dep[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		// printf("%d\n", u);
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (e[i].w && dep[to] > INF) {
				dep[to] = dep[u] + 1;
				q.push(to);
			}
		}
	}
	return dep[t] < INF;
}
int dfs(int s, int t, int l) {
	if (s == t || !l) {
		return l;
	}
	int fl = 0, f;
	for (int i = cur[s]; i; i = e[i].nx) {
		int to = e[i].v;
		cur[s] = i;
		if (dep[to] == dep[s] + 1 && (f = dfs(to, t, std::min(l, e[i].w)))) {
			e[i].w -= f;
			e[i ^ 1].w += f;
			fl += f;
			l -= f;
			if (!l) break;
		}
	}
	return fl;
}
int Dinic(int s, int t) {
	int maxf = 0;
	while (bfs(s, t)) {
		// printf("%d\n", maxf);
		maxf += dfs(s, t, INF);
	}
	return maxf;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x[i], &y[i], &z);
		add(x[i], y[i], z);
	}
	printf("%d ", Dinic(1, n));
	memset(head, 0, sizeof(head));
	memset(e, 0, sizeof(e));
	ecnt = 1;
	for (int i = 1; i <= m; i++) {
		add(x[i], y[i], 1);
	}
	printf("%d", Dinic(1, n));
}
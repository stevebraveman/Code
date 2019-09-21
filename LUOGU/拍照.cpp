#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000010
#define INF 2000000000
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
int head[MAXN], tot, r, k, ecnt = 1, n, m, x, y, z, dep[MAXN], cur[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
bool bfs(int s, int t) {
	for (int i = 1; i <= k; i++) {
		cur[i] = head[i];
		dep[i] = 0x7f7f7f7f;
	}
	std::queue <int> q;
	q.push(s);
	dep[s] = 0;
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
	return dep[t] < INF;
}
int dfs(int s, int t, int l) {
	if (s == t || !l) {
		return l;
	}
	int fl = 0, f;
	for (int i = cur[s]; i; i = e[i].nx) {
		cur[s] = i;
		int to = e[i].v;
		if (dep[to] == dep[s] + 1 && (f = dfs(to, t, std::min(e[i].w, l)))) {
			fl += f;
			l -= f;
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
int main() {
	scanf("%d%d", &n, &m);
	r = m + n + 1;
	k = r + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		add(r, i, x);
		tot += x;
		scanf("%d", &x);
		while (x) {
			add(i, n + x, INF);
			scanf("%d", &x);
		}
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &x);
		add(i + n, k, x);
	}
	printf("%d", tot - Dinic(r, k));
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000010
#define INF 2000000000
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
int head[MAXN], ecnt = 1, n, m, x, y, cur[MAXN], dep[MAXN / 10], k, val[MAXN], G[101][101];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[f], 0};
	head[t] = ecnt;
}
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	for (int i = 1; i <= n; i++) {
		cur[i] = head[i];
	}
	std::queue <int> q;
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
	return dep[t] < INF;
}
int dfs(int s, int t, int l) {
	if (s == t || !l) {
		return l;
	}
	int f, fl = 0;
	for (int i = cur[s]; i; i = e[i].nx) {
		int to = e[i].v;
		cur[s] = i;
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
int main() {
	scanf("%d%d", &k, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &val[i], &y);
		for (int i = 1; i <= y; i++) {
			scanf("%d", &x);
			G[i][x] = 1;
		}
	}
	for (int k = 1; i <= n; i++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				G[i][j] |= G[i][k] & G[k][j];
			}
		}
	}
}
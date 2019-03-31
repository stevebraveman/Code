#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdio>
#define MAXN 1000100
#define INF 2000000000
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
}e[MAXN << 2];
std::queue <int> q;
int head[MAXN], ecnt = 1, n, m, r, k, x, y, cur[MAXN], dep[MAXN], c1, c2, ans, p;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	while (!q.empty()) q.pop();
	for (int i = 1; i <= n + 2 + m * 2; i++) {
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
int dfs(int u, int t, int l) {
	if (!l || u == t) {
		return l;
	}
	int fl = 0, f;
	for (int i = cur[u]; i; i = e[i].nx) {
		cur[u] = i;
		int to = e[i].v;
		if (dep[to] == dep[u] + 1 && (f = dfs(to, t, min(l, e[i].w)))) {
			fl += f;
			l -= f;
			e[i ^ 1].w += f;
			e[i].w -= f;
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
	scanf("%d", &n);
	r = n + 1;
	k = n + 2;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		ans += x;
		add(r, i, x);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		ans += x;
		add(i, k, x);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &p, &c1, &c2);
		add(r, k + i, c1);
		add(k + i + m, k, c2);
		ans += (c1 + c2);
		for (int j = 1; j <= p; j++) {
			scanf("%d", &x);
			add(n + 2 + i, x, INF);
			add(x, n + 2 + i + m, INF);
		}
	}
	printf("%d\n", ans - Dinic(r, k));
}
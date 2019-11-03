#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#define MAXN 100010
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, y, z, dis[MAXN], in[MAXN], ans;
bool vis[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void spfa(int s) {
	for (int i = 1; i <= n + 1; i++) {
		dis[i] = 0x7fffffff;
		vis[i] = 0;
	}
	std::queue <int> q;
	q.push(s);
	dis[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		in[u]++;
		if (in[u] == n) {
			puts("NO SOLUTION");
			exit(0);
		}
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[u] + e[i].w) {
				dis[to] = dis[u] + e[i].w;
				if (!vis[to]) {
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(y, x, z);
	}
	for (int i = 1; i <= n; i++) {
		add(n + 1, i, 0);
	}
	spfa(n + 1);
	for (int i = 1; i <= n; i++) {
		ans = std::min(ans, dis[i]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", dis[i] - ans);
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define MAXN 2010
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
int head[MAXN], ecnt, dis[MAXN];
int n, m, x[MAXN], y[MAXN], fa[MAXN], _x, _y, tim[MAXN];
bool vis[MAXN], ivis[MAXN], __[MAXN], fl[MAXN];
std::vector<int> g1[MAXN << 1], g2[MAXN << 1];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
int find(int x) {
	if (x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}
void dfs1(int u) {
	for (int i = 0; i < (int)g1[u].size(); i++) {
		int to = g1[u][i];
		if (vis[to]) continue;
		vis[to] = 1;
		dfs1(to);
	}
}
void dfs2(int u) {
	for (int i = 0; i < (int)g2[u].size(); i++) {
		int to = g2[u][i];
		if (ivis[to]) continue;
		ivis[to] = 1;
		dfs2(to);
	}
}
bool spfa(int s) {
	memset(__, 0, sizeof(__));
	memset(dis, 0x7f, sizeof(dis));
	memset(tim, 0, sizeof(tim));
	std::queue <int> q;
	q.push(s);
	dis[s] = 0;
	__[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		// printf("%d: ", u);
		__[u] = 0;
		tim[u]++;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[u] + e[i].w) {
				dis[to] = dis[u] + e[i].w;
				// printf("%d ", to);
				if (tim[to] > n) return 0;
				if (!__[to]) {
					q.push(to);
					__[to] = 1;
				}
			}
		}
	}
	return 1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		g1[x[i]].push_back(y[i]);
		g2[y[i]].push_back(x[i]);
	}
	dfs1(1);
	dfs2(n);
	if (!vis[n]) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] && ivis[i]) fl[i] = 1;
	}
	fl[1] = fl[n] = 1;
	for (int i = 1; i <= m; i++) {
		if (fl[x[i]] && fl[y[i]]) {
			add(y[i], x[i], 9);
			add(x[i], y[i], -1);
		}
	}
	if (!spfa(1)) {
		// puts("OK");
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		dis[i] = -dis[i];
	}
	printf("%d %d\n", n, m);
	for (int i = 1; i <= m; i++) {
		if (fl[x[i]] && fl[y[i]]) {
			printf("%d %d %d\n", x[i], y[i], dis[y[i]] - dis[x[i]]);
		}
		else {
			printf("%d %d 1\n", x[i], y[i]);
		}
	}
}
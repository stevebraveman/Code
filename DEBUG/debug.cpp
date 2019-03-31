#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1100
int opt, n, m, a[MAXN], maxx = 0, tot, ans, p[MAXN], x, y, head[MAXN], ecnt;
bool flag;
bool vis[MAXN];
struct Edge {
	int v, nx;
}e[MAXN << 2];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int u, int end) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to]) continue;
		vis[to] = 1;
		if (to == end || flag == 1) {
			flag = 1;
			ans ^= p[to];
			return;
		}
		dfs(to, end);
	}
}
int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	while (m--) {
		scanf("%d%d%d", &opt, &x, &y);
		if (opt == 2) {
			flag = 0;
			ans = 0;
			memset(vis, 0, sizeof(vis));
			dfs(x, y);
			ans ^= p[x];
			printf("%d\n", ans);
		}
		else {
			p[x] = y;
		}
	}
}
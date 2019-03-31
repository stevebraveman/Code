#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
struct Edge {
	int v, nx, w;
}e[MAXN];
int head[MAXN], ecnt, n, m, x, y, z, dp[MAXN][20];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void dfs(int u, int t) {
	for (int i = head[u]; i; i = e[i].nx) {
		
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	dfs(1, 0);
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, y, k, dep[MAXN], dis[MAXN][22]; 
int dish[MAXN][22], ans[MAXN][22], tot[MAXN], disk[MAXN][22], c[MAXN][22];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs2(int u, int f, int p) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dis[u][p + 1] += dis[to][p];
		dfs2(to, u, p);
	}
}
void dfs3(int u, int f, int p) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		disk[to][p] = disk[u][p - 1] - dis[to][p - 2] + dis[to][p];
		dfs3(to, u, p);
	}
}
void dp(int u, int f) {

}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dis[i][0]);
		disk[i][0] = dis[i][0];
	}
	for (int i = 0; i < k; i++) {
		dfs2(1, 1, i);
	}
	for (int i = 1; i <= k; i++) {
		disk[1][i] = dis[1][i];
		dfs3(1, 1, i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			tot[i] = tot[i] + disk[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", tot[i]);
	}
}

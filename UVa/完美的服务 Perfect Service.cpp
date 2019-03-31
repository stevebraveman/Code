#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 100010
#define INF 20000000
struct Edge {
	int v, nx;
}e[MAXN];
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int f[MAXN][4], n, m, x, y, head[MAXN], ecnt;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int u, int fa) {
	f[u][0] = 1;
	f[u][1] = 0;
	f[u][2] = INF;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa) continue;
		dfs(to, u);
		f[u][0] += min(f[to][1], f[to][0]);
		f[u][1] += f[to][2];
	}
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa) continue;
		f[u][2] = min(f[u][2], f[u][1] - f[to][2] + f[to][0]);
	}
	return;
}
int main() {
	while (1) {
		memset(e, 0, sizeof(e));
		ecnt = 0;
		memset(head, 0, sizeof(head));
		memset(f, 0, sizeof(f));
		scanf("%d", &n);
		for (int i = 1; i < n; i++) {
			scanf("%d%d", &x, &y);
			add(x, y);
			add(y, x);
		}
		dfs(1, 0);
		printf("%d\n", min(f[1][0], f[1][2]));
		scanf("%d", &m);
		if (m == -1) break;
	}
}
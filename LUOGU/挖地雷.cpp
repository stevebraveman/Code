#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 100100
struct Edge {
	int v, nx;
}e[MAXN];
int head[MAXN], maxa, ecnt, w[MAXN], n, x, path[MAXN], tp[MAXN];
bool vis[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int u, int sum, int m) {
	bool flag = 0;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to]) {
			flag = 1;
			continue;
		}
	}
	if (flag) {
		if (sum > maxa) {
			maxa = sum;
			for (int i = 1; i <= m; i++) {
				path[i] = tp[i];
			}
		}
		return;
	}
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to]) continue;
		tp[m + 1] = to;
		vis[to] = 1;
		dfs(to, sum + w[to], m + 1);
		vis[to] = 0;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			scanf("%d", &x);
			if (x) {
				add(i, j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		vis[i] = 1;
		tp[1] = i;
		dfs(i, w[i], 1);
		for (int i = 1; i <= n; i++) {
			vis[i] = 0;
		}
	}
	for (int i = 1; path[i]; i++) {
		printf("%d ", path[i]);
	}
	puts("");
	printf("%d", maxa);
}
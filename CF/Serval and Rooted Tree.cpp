#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x7fffffff
#define MAXN 300011
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, p;
int mm[MAXN], f[MAXN], son[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int u, int fa) {
	if (!son[u]) {
		f[u] = 1;
		m++;
		return;
	}
	if (mm[u]) f[u] = INF;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa) continue;
		dfs(to, u);
		if (!mm[u]) f[u] += f[to];
		else f[u] = std::min(f[u], f[to]);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &mm[i]);
	}
	for (int i = 2; i <= n; i++) {
		scanf("%d", &x);
		add(i, x);
		add(x, i);
		son[x] = 1;
	}
	dfs(1, 0);
	printf("%d", m + 1 - f[1]);
}
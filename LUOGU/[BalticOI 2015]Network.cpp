#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <ctime>
#define MAXN 510000
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], ecnt, n, x, y, in[MAXN], tot, ste, p[MAXN], ans;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int f, int u) {
	if (in[u] == 1) {
		p[++tot] = u;
	}
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs(u, to);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
		in[x]++;
		in[y]++;
	}
	dfs(0, 1);
	printf("%d", tot - (tot >> 1));
	for (int i = 1; i <= (tot >> 1); i++) {
		if (p[i] >= p[i + tot / 2]) std::swap(p[i], p[i + tot / 2]);
		printf("\n%d %d", p[i], p[i + tot / 2]);
	}
	if (tot & 1) {
		printf("\n%d %d", p[tot / 2], p[tot]);
	}
	return 0;
}
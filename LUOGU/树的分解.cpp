#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 100010
int a[MAXN];
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, y, siz[MAXN], ans, T;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int u, int f) {
	siz[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs(to, u);
		siz[u] += siz[to];
	}
	if (siz[u] == m) {
		siz[u] = 0;
		ans++;
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		memset(siz, 0, sizeof(siz));
		memset(head, 0, sizeof(head));
		ecnt = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i < n; i++) {
			scanf("%d%d", &x, &y);
			add(x, y);
			add(y, x);
		}
		ans = 0;
		if (n % m) {
			puts("NO");
			continue;
		}
		dfs(1, 1);
		if (ans != n / m) {
			puts("NO");
			continue;
		}
		else {
			puts("YES");
		}
	}
}
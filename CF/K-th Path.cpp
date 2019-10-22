#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200010
#define int long long
struct E {
	int u, v, w;
} e[MAXN << 2];
int n, m, x, y, p, z, G[810][810], tot, vis[MAXN], col[MAXN], l;
bool cmp(E a, E b) {
	return a.w < b.w;
}
signed main() {
	scanf("%I64d%I64d%I64d", &n, &m, &p);
	for (int i = 1; i <= m; i++) {
		scanf("%I64d%I64d%I64d", &x, &y, &z);
		e[i].u = x;
		e[i].v = y;
		e[i].w = z;
	}
	memset(G, 0x3f, sizeof(G));
	std::sort(e + 1, e + 1 + m, cmp);
	for (int i = 1; i <= p; i++) {
		vis[e[i].u] = 1;
		vis[e[i].v] = 1;
	}
	for (int i = 1; i <= n; i++) {
		col[i] = col[i - 1] + vis[i];
	}
	l = col[n];
	for (int i = 1; i <= p; i++) {
		G[col[e[i].v]][col[e[i].u]] = G[col[e[i].u]][col[e[i].v]] = e[i].w;
	}
	memset(e, 0, sizeof(e));
	n = l;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				G[i][j] = std::min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (i == j) continue;
			e[++tot].u = i;
			e[tot].v = j;
			e[tot].w = G[i][j];
		}
	}
	std::sort(e + 1, e + 1 + tot, cmp);
	printf("%I64d", e[p].w);
}
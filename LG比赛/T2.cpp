#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 300010
struct E {
	int u, v, w;
}_[MAXN << 1];
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
int head[MAXN], ecnt, q, n, m, x, y, z, dis[MAXN], qx, qy, fa[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void dfs(int u, int f) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dis[to] = dis[u] ^ e[i].w;
		dfs(to, u);
	}
}
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &_[i].u, &_[i].v, &_[i].w);
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int _x = find(_[i].u);
		int _y = find(_[i].v);
		if (_x != _y) {
			fa[_x] = _y;
			add(_[i].u, _[i].v, _[i].w);
			add(_[i].v, _[i].u, _[i].w);
		}
	}
	// for (int i = 1; i <= n; i++) {
		// if (!dfn[i]) tarjan(i, i);
	// }
	// for (int i = 1; i <= m; i++) {
		// if (in[x[i]] != in[y[i]]) {
			// add(x[i], y[i], z[i]);
			// add(y[i], x[i], z[i]);
		// }
		// else {
			// dis[x[i]] ^= z[i];
		// }
	// }
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d ", in[i]);
	// }
	// puts("");
	dfs(1, 1);
	while (q--) {
		scanf("%d%d", &qx, &qy);
		printf("%d\n", dis[qx] ^ dis[qy]);
	}
}
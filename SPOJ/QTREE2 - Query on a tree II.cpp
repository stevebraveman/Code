#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10010
#define LOG 15
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, y, z, T, anc[MAXN][LOG + 1], dep[MAXN], dis[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void dfs(int u, int f, int d) {
	dep[u] = d;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dis[to] = dis[u] + e[i].w;
		anc[to][0] = u;
		dfs(to, u, d + 1);
	}
}
void swim(int &x, int h) {
	for (int i = 0; h > 0; i++) {
		if (h & 1) x = anc[x][i];
		h >>= 1;
	}
}
int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	swim(x, dep[x] - dep[y]);
	if (x == y) return x;
	for (int i = LOG; i >= 0; i--) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0];
}
char op[6];
int query(int a, int b, int k) {
	int lc = LCA(a, b);
	if (dep[a] - dep[lc] + 1 <= k) {
		k = dep[a] + dep[b] - dep[lc] * 2 + 2 - k;
		a = b;
	}
	// printf("%d\n", k);
	for (int i = LOG; i >= 0; i--) {
		if (k >= (1 << i) + 1) {
			// printf("%d\n", k);
			a = anc[a][i];
			k -= (1 << i);
		}
	}
	return a;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(head, 0, sizeof(head));
		memset(dis, 0, sizeof(dis));
		memset(anc, 0, sizeof(anc));
		memset(dep, 0, sizeof(dep));
		ecnt = 0;
		for (int i = 1; i < n; i++) {
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z);
			add(y, x, z);
		}
		dfs(1, 0, 1);
		for (int i = 1; i <= LOG; i++) {
			for (int j = 1; j <= n; j++) {
				anc[j][i] = anc[anc[j][i - 1]][i - 1];
			}
		}
		while (1) {
			scanf("%s", op);
			if (op[1] == 'O') break;
			else if (op[1] == 'I') {
				scanf("%d%d", &x, &y);
				printf("%d\n", dis[x] + dis[y] - 2 * dis[LCA(x, y)]);
			}
			else if (op[1] == 'T') {
				scanf("%d%d%d", &x, &y, &z);
				printf("%d\n", query(x, y, z));
			}
		}
	}
}
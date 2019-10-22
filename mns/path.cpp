#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define MAXN 100010
#define LOG 21
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, y, dep[MAXN], anc[MAXN][LOG + 1], top, path[MAXN];
bool vis[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int u, int f, int d) {
	dep[u] = d;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		anc[to][0] = u;
		dfs(to, u, d + 1);
	}
}
void swim(int &x, int h) {
	for (int i = 0; h; i++) {
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
void hamilton(int u) {
	for (int i = 1; i <= n; i++) {
		if (i == u) continue;
		if ((dep[i] + dep[u] - 2 * dep[LCA(i, u)]) > 3) continue;
		if (vis[i] && top == n && i == path[1]) {
			puts("Yes");
			for (int i = 1; i <= top; i++) {
				printf("%d ", path[i]);
			}
			exit(0);
		}
		else if (!vis[i] && top != n) {
			vis[i] = 1;
			path[++top] = i;
			hamilton(i);
			top--;
			vis[i] = 0;
		}
		else {
			continue;
		}
	}
}
int main() {
	// freopen("path.in", "r", stdin)s
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(1, 1, 0);
	for (int i = 1; i <= LOG; i++) {
		for (int j = 1; j <= n; j++) {
			anc[j][i] = anc[anc[j][i - 1]][i - 1];
		}
	}
	// puts("OK");
	if (n <= 20) {
		hamilton(1);
	}
	else {
		for (int i = 1; i <= n; i++) {
			path[i] = i;
		}
		while (1) {
			std::random_shuffle(path + 1, path + 1 + n);
			path[n + 1] = path[1];
			bool fl = false;
			for (int i = 2; i <= n + 1; i++) {
				if (dep[i] + dep[i - 1] - 2 * dep[LCA(i, i - 1)] > 3) {
					fl = true;
					break;
				}
			}
			if (!fl) {
				for (int i = 1; i <= n; i++) {
					printf("%d ", path[i]);
				}
				break;
			}
		}
	}
}
/*
8
1 2
2 3
3 4
4 5
4 6
4 7
7 8
 */
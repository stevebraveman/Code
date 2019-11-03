#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define MAXN 100010
struct Edge {
	int nx, v;
}e[MAXN << 2];
int head[MAXN], ecnt, n, col[MAXN], m, x, y, bj[2010][8010];
std::vector <int> v[MAXN];
void dfs(int c, int u) {
	if (col[u] == c) {
		puts("No solution");
		exit(0);
	}
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		while (x != 0) {
			v[i].push_back(x);
			scanf("%d", &x);
			bj[i][x] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!bj[i][j] && !bj[j][i]) add(i, j), add(j, i);
		}
	}
	for (int i = 1; i <= n; i++) {

	}
}
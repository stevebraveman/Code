#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
#define LOG 22
struct Edge {
	int v, nx;
}e[MAXN << 1];
struct E {
	int u, v, w;
}_[MAXN];
int head[MAXN], ecnt, fa[MAXN], n, m, q, h[MAXN], x, y, z, num, p[MAXN], cnt;
int anc[MAXN][LOG + 1], dep[MAXN], b[MAXN], son[MAXN];
bool cmp(E a, E b) {
	return a.w < b.w;
}
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int u, int f, int d) {
	// printf("%d\n", u);
	dep[u] = d;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
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
	// printf("%d\n", dep[x] - dep[y]);
	swim(x, dep[x] - dep[y]);
	// printf("%d\n", x);
	if (x == y) return x;
	for (int i = LOG; i >= 0; i--) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	// printf("%d\n", anc[x][0]);
	return anc[x][0];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &_[i].u, &_[i].v, &_[i].w);
	}
	num = n;
	std::sort(_ + 1, _ + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		x = find(_[i].u);
		y = find(_[i].v);
		if (x != y) {
			num++;
			p[num] = _[i].w;
			fa[x] = num;
			fa[y] = num;
			fa[num] = num;
			add(x, num), add(y, num);
			add(num, x), add(num, y);
			anc[x][0] = anc[y][0] = num;
			cnt++;
		}
	}
	dfs(num, num, 1);
	for (int i = 1; i <= LOG; i++) {
		for (int j = 1; j <= num; j++) {
			anc[j][i] = anc[anc[j][i - 1]][i - 1];
		}
		// puts("");
	}
	// for (int i = 1; i <= num; i++) {
	// 	printf("%d ", anc[i][0]);
	// }
	// puts("");
	// for (int i = 1; i <= num; i++) {
	// 	for (int j = 0; j <= LOG; j++) {
	// 		printf("%d ", anc[i][j]);
	// 	}
	// 	puts("");
	// }
	scanf("%d\n", &q);
	while (q--) {
		scanf("%d%d", &x, &y);
		if (find(x) != find(y)) puts("impossible");
		else printf("%d\n", p[LCA(x, y)]);
	}
}
/*
4 5
1 2 5
1 3 2
2 3 11
2 4 6
3 4 4
3
2 3
1 4
1 2

 */
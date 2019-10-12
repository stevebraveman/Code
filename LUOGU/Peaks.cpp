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
int fa[MAXN], n, m, q, h[MAXN], x, y, z, num, p[MAXN], cnt, anc[MAXN][LOG], tim, itv[MAXN][2], lin[MAXN], rin[MAXN];
int head[MAXN], ecnt, ls[MAXN * LOG], rs[MAXN * LOG], dep[MAXN], b[MAXN], len, sum[MAXN * LOG], son[MAXN], tm, rt[MAXN * 20];
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
void build(int l, int r, int &p) {
	p = ++tim;
	if (l == r) {
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, ls[p]);
	build(m + 1, r, rs[p]);
}
void chg(int la, int &p, int l, int r, int x) {
	p = ++tim;
	ls[p] = ls[la];
	rs[p] = rs[la];
	sum[p] = sum[la] + 1;
	if (l == r) return;
	int m = (l + r) >> 1;
	if (x <= m) chg(ls[la], ls[p], l, m, x);
	else chg(rs[la], rs[p], m + 1, r, x);
}
int ask(int x, int y, int l, int r, int k) {
	if (l == r) return l;
	int m = (l + r) >> 1;
	int d = sum[rs[y]] - sum[rs[x]];
	if (k <= d) return ask(rs[x], rs[y], m + 1, r, k);
	else return ask(ls[x], ls[y], l, m, k - d);
}
void dfs(int u, int f) {
	// printf("%d\n", u);
	for (int i = 1; i < LOG; i++) {
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
	}
	lin[u] = tm;
	if (!son[u]) {
		lin[u] = ++tm;
		// printf("%d\n", tm);
		chg(rt[tm - 1], rt[tm], 1, len, h[u]);
		// puts("OK");
		return;
	}
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		// printf("%d\n", to);
		if (to == f) continue;
		dfs(to, u);
	}
	rin[u] = tm;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
		b[i] = h[i];
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	std::sort(b + 1, b + 1 + n);
	len = std::unique(b + 1, b + 1 + n) - b - 1;
	for (int i = 1; i <= m; i++) {
		h[i] = std::lower_bound(b + 1, b + 1 + len, h[i]) - b;
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
			// printf("%d %d\n", num, x);
			// printf("%d %d\n", num, y);
			son[num]++;
			anc[x][0] = anc[y][0] = num;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	build(1, len, rt[0]);
	// printf("%d\n", num);
	dfs(num, num);
	// puts("OK");
	// for (int i = 1; i <= tim; i++) {
	// 	printf("%d ", sum[i]);
	// }
	// puts("");
	// for (int i = 1; i <= tm; i++) {
	// 	printf("%d ", rt[i]);
	// }
	// puts("");
	while (q--) {
		scanf("%d%d%d", &x, &y, &z);
		for (int i = LOG - 1; i >= 0; i--) {
			if (anc[x][i] && p[anc[x][i]] <= y) x = anc[x][i];
		}
		// printf("%d\n", sum[rt[rin[x]]] - sum[rt[lin[x]]]);
		if (sum[rt[rin[x]]] - sum[rt[lin[x]]] < z) {
			puts("-1");
			continue;
		}
		printf("%d\n", b[ask(rt[lin[x]], rt[rin[x]], 1, len, z)]);
	}
}
/*
10 11 4
1 2 3 4 5 6 7 8 9 10
1 4 4
2 5 3
9 8 2
7 8 10
7 1 4
6 7 1
6 4 8
2 1 5
10 8 10
3 4 7
3 4 6
1 5 2
1 5 6
1 5 8
8 9 2
 */
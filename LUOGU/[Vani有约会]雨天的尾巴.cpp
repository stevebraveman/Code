#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#define MAXN 101000
#define LOG 20
struct Treap {
	int v, dat, num;
	int cnt, siz, maxx, maxid;
	int l, r;
}a[MAXN * LOG << 2];
struct Edge {
	int v, nx;
}e[MAXN << 1];
int tot, rt[MAXN], head[MAXN], ecnt, anc[MAXN][LOG + 1], dep[MAXN], ans[MAXN], fa[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
int New(int val, int num) {
	tot++;
	a[tot].v = val;
	a[tot].num = num;
	a[tot].dat = rand();
	a[tot].cnt = a[tot].siz = 1;
	a[tot].maxx = num;
	a[tot].maxid = val;
	return tot;
}
void update(int p) {
	a[p].siz = a[p].cnt + a[a[p].l].siz + a[a[p].r].siz;
	a[p].maxx = a[p].num;
	a[p].maxid = a[p].v;
	int maxx = a[p].maxx, maxid = a[p].maxid;
	if (a[a[p].l].maxx > maxx || (a[a[p].l].maxx == maxx && a[a[p].l].maxid < maxid)) {
		maxx = a[a[p].l].maxx;
		maxid = a[a[p].l].maxid;
	}
	if (a[a[p].r].maxx > maxx || (a[a[p].r].maxx == maxx && a[a[p].r].maxid < maxid)) {
		maxx = a[a[p].r].maxx;
		maxid = a[a[p].r].maxid;
	}
	a[p].maxx = maxx;
	a[p].maxid = maxid;
}
void zig(int &p) {
	int q = a[p].l;
	a[p].l = a[q].r, a[q].r = p, p = q;
	update(a[p].r), update(p);
}
void zag(int &p) {
	int q = a[p].r;
	a[p].r = a[q].l, a[q].l = p, p = q;
	update(a[p].l), update(p);
}
void insert(int &p, int val, int num) {
	if (!p) {
		p = New(val, num);
		return;
	}
	if (val == a[p].v) {
		a[p].num += num;
		update(p);
		return;
	}
	if (val < a[p].v) {
		insert(a[p].l, val, num);
		if (a[p].dat < a[a[p].l].dat) zig(p);
	}
	else {
		insert(a[p].r, val, num);
		if (a[p].dat < a[a[p].r].dat) zag(p);
	}
	update(p);
}
int find(int x) {
	if (x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	if (!y) return;
	insert(rt[x], a[y].v, a[y].num);
	merge(x, a[y].l);
	merge(x, a[y].r);
}
void dfs(int f, int u, int d) {
	dep[u] = d;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		anc[to][0] = u;
		dfs(u, to, d + 1);
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
void dfs1(int f, int u) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs1(u, to);
		int x = find(u);
		int y = find(to);
		if (a[rt[x]].siz < a[rt[y]].siz) std::swap(x, y);
		fa[y] = x;
		// printf("Merge: %d --> %d\n", y, x);
		merge(x, rt[y]);
	}
	int q = find(u);
	ans[u] = a[rt[q]].maxid;
}
int n, m, x, y, z;
int main() {
	srand(time(NULL));
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	dfs(1, 1, 1);
	for (int i = 1; i <= LOG; i++) {
		for (int j = 1; j <= n; j++) {
			anc[j][i] = anc[anc[j][i - 1]][i - 1];
		}
	}
	while (m--) {
		scanf("%d%d%d", &x, &y, &z);
		insert(rt[x], z, 1);
		insert(rt[y], z, 1);
		int lc = LCA(x, y);
		// printf("%d\n", lc);
		insert(rt[lc], z, -1);
		// if (lc == 1) continue;
		insert(rt[anc[lc][0]], z, -1);
	}
	dfs1(1, 1);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
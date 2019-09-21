#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define MAXN 100010
#define INF 19260817
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Segtree {
	int a[MAXN], lazy[MAXN << 2], tmin[MAXN << 2];
	void pd(int p) {
		tmin[p] = min(tmin[ls(p)], tmin[rs(p)]);
	}
	void build(int p, int l, int r) {
		lazy[p] = 0;
		if (l == r) {
			tmin[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(ls(p), l, m);
		build(rs(p), m + 1, r);
		pd(p);
	}
	void f(int p, int l, int r, int k) {
		lazy[p] += k;
		tmin[p] += k;
	}
	void pushd(int p, int l, int r) {
		if (lazy[p]) {
			int m = (l + r) >> 1;
			f(ls(p), l, m, lazy[p]);
			f(rs(p), m + 1, r, lazy[p]);
			lazy[p] = 0;
			return;
		}
	}
	void update(int x, int y, int l, int r, int p, int k) {
		if (x <= l && y >= r) {
			lazy[p] += k;
			tmin[p] += k;
			return;
		}
		pushd(p, l, r);
		int m = (l + r) >> 1;
		if (x <= m) update(x, y, l, m, ls(p), k);
		if (y > m) update(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	int ask(int x, int y, int l, int r, int p) {
		int ans = INF;
		if (x <= l && y >= r) {
			return tmin[p];
		}
		pushd(p, l, r);
		int m = (l + r) >> 1;
		if (x <= m) ans = min(ans, ask(x, y, l, m, ls(p)));
		if (y > m) ans = min(ans, ask(x, y, m + 1, r, rs(p)));
		return ans;
	}
} tree;
struct cow {
	int l, r;
} c[MAXN];
int n, m, ans = 0;
bool cmp(cow a, cow b) {
	return (a.l > b.l || (a.l == b.l && a.r < b.r));
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tree.a[i]);
	}
	tree.build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &c[i].l, &c[i].r);
	}
	std::sort(c + 1, c + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		if (tree.ask(c[i].l, c[i].r, 1, n, 1) > 0) {
			tree.update(c[i].l, c[i].r, 1, n, 1, -1);
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
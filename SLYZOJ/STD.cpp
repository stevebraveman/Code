#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define MAXN 2000000
struct Segtree {
	int a[MAXN], b[MAXN << 2], lazy[MAXN << 2];
	void pd(int p) {
		b[p] = b[ls(p)] ^ b[rs(p)];
	}
	void build(int l, int r, int p) {
		lazy[p] = 0;
		if (l == r) {
			b[p] = a[l];
			return;
		}
		int m = l + r >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	void f(int l, int r, int p, int k) {
		lazy[p] ^= k;
		b[p] ^= ((r - l + 1) & 1 ? k : 0);
	}
	void pushd(int l, int r, int p) {
		if (lazy[p]) {
			int m = l + r >> 1;
			f(l, m, ls(p), lazy[p]);
			f(m + 1, r, rs(p), lazy[p]);
			lazy[p] = 0;
			return;
		}
	}
	void upd(int x, int l, int r, int p, int k) {
		if (l == r) {
			b[p] = k;
			return;
		}
		int m = l + r >> 1;
		if (x <= m) upd(x, l, m, ls(p), k);
		else upd(x, m + 1, r, rs(p), k);
		pd(p);
	}
	void upr(int x, int y, int l, int r, int k, int p) {
		if (x <= l && y >= r) {
			lazy[p] ^= k;
			b[p] ^= ((r - l + 1) & 1 ? k : 0);
			return;
		}
		int m = l + r >> 1;
		if (x <= m) upr(x, y, l, m, k, ls(p));
		if (y > m) upr(x, y, m + 1, r, k, rs(p));
		pd(p);
	}
	int ask(int x, int y, int l, int r, int p) {
		int s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		int m = l + r >> 1;
		if (x <= m) s ^= ask(x, y, l, m, ls(p));
		if (y > m) s ^= ask(x, y, m + 1, r, rs(p));
		return s;
	}
}tr;
int n, m, l, r, k, op;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tr.a[i]);
	}
	tr.build(1, n, 1);
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &l, &r);
			tr.upd(l, 1, n, 1, r);
		}
		if (op == 2) {
			scanf("%d%d%d", &l, &r, &k);
			tr.upr(l, r, 1, n, k, 1);
		}
		if (op == 3) {
			scanf("%d%d", &l, &r);
			printf("%d\n", tr.ask(l, r, 1, n, 1));
		}
	}
}
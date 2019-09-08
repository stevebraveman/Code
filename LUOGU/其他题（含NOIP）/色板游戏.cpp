#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define MAXN 1001000
void swap(int &x, int &y) {
	int t = x;
	x = y;
	y = t;
}
struct Segtree {
	int b[MAXN << 2], lazy[MAXN << 2];
	void pd(int p) {
		b[p] = b[ls(p)] | b[rs(p)];
	}
	void build(int p, int l, int r) {
		lazy[p] = 0;
		if (l == r) {
			b[p] = 1;
			return;
		}
		int m = (l + r) >> 1;
		build(ls(p), l, m);
		build(rs(p), m + 1, r);
		pd(p);
	}
	void f(int p, int l, int r, int k) {
		lazy[p] = k;
		b[p] = k;
	}
	void pushd(int p, int l, int r) {
		if (lazy[p]) {
			int m = (l + r) >> 1;
			f(ls(p), l, m, lazy[p]);
			f(rs(p), m + 1, r, lazy[p]);
			lazy[p] = 0;
		}
	}
	void update(int x, int y, int l, int r, int p, int k) {
		if (x <= l && y >= r) {
			b[p] = k;
			lazy[p] = k;
			return;
		}
		pushd(p, l, r);
		int m = (l + r) >> 1;
		if (x <= m) update(x, y, l, m, ls(p), k);
		if (y > m) update(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	int qor(int x, int y, int l, int r, int p) {
		int s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		pushd(p, l, r);
		int m = (l + r) >> 1;
		if (x <= m) s |= qor(x, y, l, m, ls(p));
		if (y > m) s |= qor(x, y, m + 1, r, rs(p));
		return s;
	}
} tree;
int n, m, l, r, ans, t, k, tot, k2;
char op;
int main() {
	scanf("%d%d%d", &n, &t, &m);
	tree.build(1, 1, n);
	while (m--) {
		std::cin >> op;
		if (op == 'C') {
			scanf("%d%d%d", &l, &r, &k);
			if (l > r) swap(l, r);
			k = 1 << (k - 1);
			tree.update(l, r, 1, n, 1, k);
		}
		else {
			scanf("%d%d", &l, &r);
			if (l > r) swap(l, r);
			tot = 0;
			ans = tree.qor(l, r, 1, n, 1);
			for (int i = 0; i < t; i++) {
				if (ans & (1 << i)) tot++; 
			}
			printf("%d\n", tot);
		}
	}
}
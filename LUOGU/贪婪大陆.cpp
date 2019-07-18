#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
int n, m, x, y, z = 0, op;
template <typename Tp>
Tp max(Tp a, Tp b) {
	if (a > b) return a;
	else return b;
}
struct Segtree {
	int a[MAXN], b[MAXN << 2], lazy[MAXN << 2];
	void pd(int p) {
		b[p] = max(b[ls(p)], b[rs(p)]);
	}
	void f(int l, int r, int k, int p) {
		b[p] += k;
		lazy[p] += k;
		return;
	}
	void pushd(int l, int r, int p) {
		if (lazy[p]) {
			int m = (l + r) >> 1;
			f(l, m, lazy[p], ls(p));
			f(m + 1, r, lazy[p], rs(p));
			lazy[p] = 0;
		}
	}
	void upd(int x, int y, int l, int r, int p, int k) {
		if (x <= l && y >= r) {
			b[p] += k;
			lazy[p] += k;
			return;
		}
		int m = (l + r) >> 1;
		pushd(l, r, p);
		if (x <= m) upd(x, y, l, m, ls(p), k);
		if (y > m) upd(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	int ask(int x, int y, int l, int r, int p) {
		int ans = -0x7fffffff;
		if (x <= l && y >= r) {
			return b[p];
		}
		int m = (l + r) >> 1;
		pushd(l, r, p);
		if (x <= m) ans = max(ans, ask(x, y, l, m, ls(p)));
		if (y > m) ans = max(ans, ask(x, y, m + 1, r, rs(p)));
		return ans;
	}
}tr;
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			tr.upd(x, y, 1, n, 1, 1);
		}
		else {
			printf("%d\n", tr.ask(x, y, 1, n, 1));
		}
	}
}
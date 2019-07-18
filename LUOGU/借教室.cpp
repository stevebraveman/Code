#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000005
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define INF 0x7fffffff
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
struct Segtree {
	int lazy[MAXN << 2], a[MAXN], tmin[MAXN << 2];
	inline void pd(int p) {
		tmin[p] = min(tmin[ls(p)], tmin[rs(p)]);
	}
	void build(int l, int r, int p) {
		lazy[p] = 0;
		if (l == r) {
			tmin[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	inline void f(int p, int l, int r, int k) {
		tmin[p] += k;
		lazy[p] += k;
	}
	inline void pushd(int p, int l, int r) {
		int m = (l + r) >> 1;
		f(ls(p), l, m, lazy[p]);
		f(rs(p), m + 1, r, lazy[p]);
		lazy[p] = 0;
	}
	void update(int x, int y, int l, int r, int p, int k) {
		if (x <= l && y >= r) {
			tmin[p] += k;
			lazy[p] += k;
			return;
		}
		pushd(p , l , r);
		int m = (l + r) >> 1;
		if (x <= m) update(x, y, l, m, ls(p), k);
		if (y > m) update(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	int qmin(int x, int y, int l, int r, int p) {
		int s = INF;
		if (x <= l && y >= r) {
			return tmin[p];
		}
		int m = (l + r) >> 1;
		pushd(p, l, r);
		if (x <= m) s = min(s, qmin(x, y, l, m, ls(p)));
		if (y > m) s = min(s, qmin(x, y, m + 1, r, rs(p)));
		return s;
	}
} tr;
int n, m, l, r, k, ansm, ans;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tr.a[i]);
	}
	tr.build(1, n, 1);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &k, &l, &r);
		ansm = tr.qmin(l, r, 1, n, 1);
		if (ansm < k) {
			printf("-1\n%d", i);
			return 0;
		}
		tr.update(l, r, 1, n, 1, -k);
	}
	puts("0");
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define MAXN 200010
int lazy[MAXN << 2], n, m, a[MAXN];
double sia[MAXN << 2], coa[MAXN << 2];
void pd(int p) {
	sia[p] = sia[ls(p)] + sia[rs(p)];
	coa[p] = coa[ls(p)] + coa[rs(p)];
}
void build(int l, int r, int p) {
	if (l == r) {
		sia[p] = sin(1.0 * a[l]);
		coa[p] = cos(1.0 * a[l]);
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, ls(p));
	build(m + 1, r, rs(p));
	pd(p);
}
void f(int p, int k) {
	lazy[p] += k;
	double x = sin(1.0 * k), y = cos(1.0 * k);
	double c = sia[p], d = coa[p];
	coa[p] = y * d - x * c;
	sia[p] = x * d + y * c;
}
void pushd(int l, int r, int p) {
	if (lazy[p]) {
		f(ls(p), lazy[p]);
		f(rs(p), lazy[p]);
		lazy[p] = 0;
	}
}
double ask(int x, int y, int l, int r, int p) {
	double s = 0;
	if (x <= l && y >= r) {
		return sia[p];
	}
	int m = (l + r) >> 1;
	pushd(l, r, p);
	if (x <= m) s += ask(x, y, l, m, ls(p));
	if (y > m) s += ask(x, y, m + 1, r, rs(p));
	return s;
}
void chg(int x, int y, int l, int r, int k, int p) {
	if (x <= l && y >= r) {
		f(p, k);
		return;
	}
	int m = (l + r) >> 1;
	pushd(l, r, p);
	if (x <= m) chg(x, y, l, m, k, ls(p));
	if (y > m) chg(x, y, m + 1, r, k, rs(p));
	pd(p);
}
int op, l, r, k;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, n, 1);
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1) {
			scanf("%d", &k);
			chg(l, r, 1, n, k, 1);
		}
		else {
			printf("%.1lf\n", ask(l, r, 1, n, 1));
		}
	}
}
/*
5
1 3 1 5 5
5
1 5 5 5
2 3 3
2 1 5
2 2 2
2 4 4
---------
5
1 3 1 5 5
5
1 5 5 5
2 3 3
2 1 5
2 2 5
2 4 5
 */
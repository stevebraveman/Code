#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200010
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
int a[MAXN], b[MAXN << 2], lazy[MAXN << 2], c[MAXN], _ans;
void pd(int p) {
	b[p] = b[ls(p)] + b[rs(p)];
}
void build(int l, int r, int p) {
	lazy[p] = -1;
	if (l == r) {
		b[p] = a[l];
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, ls(p));
	build(m + 1, r, rs(p));
	pd(p);
}
void f(int l, int r, int k, int p) {
	b[p] = (r - l + 1) * k;
	lazy[p] = k;
}
void pushd(int l, int r, int p) {
	if (lazy[p] != -1) {
		int m = (l + r) >> 1;
		f(l, m, lazy[p], ls(p));
		f(m + 1, r, lazy[p], rs(p));
		lazy[p] = -1;
	}
}
void chg(int x, int y, int l, int r, int k, int p) {
	if (x <= l && y >= r) {
		b[p] = (r - l + 1) * k;
		lazy[p] = k;
		return;
	}
	pushd(l, r, p);
	int m = (l + r) >> 1;
	if (x <= m) chg(x, y, l, m, k, ls(p));
	if (y > m) chg(x, y, m + 1, r, k, rs(p));
	pd(p);
}
int ask(int x, int y, int l, int r, int p) {
	int s = 0;
	if (x <= l && y >= r) {
		return b[p];
	}
	pushd(l, r, p);
	int m = (l + r) >> 1;
	if (x <= m) s += ask(x, y, l, m, ls(p));
	if (y > m) s += ask(x, y, m + 1, r, rs(p));
	return s;
}
int askp(int x, int l, int r, int p) {
	if (l == r) {
		return b[p];
	}
	int m = (l + r) >> 1;
	pushd(l, r, p);
	if (x <= m) return askp(x, l, m, ls(p));
	else return askp(x, m + 1, r, rs(p));
}
int op[MAXN], L[MAXN], R[MAXN], l, r, tot, askpos, n, m;
bool chk(int x) {
	for (int i = 1; i <= n; i++) {
		a[i] = (c[i] >= x);
	}
	build(1, n, 1);
	for (int i = 1; i <= m; i++) {
		tot = ask(L[i], R[i], 1, n, 1);
		if (op[i]) {
			if (tot != 0) chg(L[i], L[i] + tot - 1, 1, n, 1, 1);
			if (tot != R[i] - L[i] + 1) chg(L[i] + tot, R[i], 1, n, 0, 1);
		}
		else {
			if (tot != 0) chg(R[i] - tot + 1, R[i], 1, n, 1, 1);
			if (tot != R[i] - L[i] + 1) chg(L[i], R[i] - tot, 1, n, 0, 1);
		}
	}
	return askp(askpos, 1, n, 1);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &op[i], &L[i], &R[i]);
	}
	l = 1;
	r = n;
	scanf("%d", &askpos);
	while (l <= r) {
		int mid = (l + r) >> 1;
		// printf("%d\n", mid);
		if (chk(mid)) {
			_ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	printf("%d\n", _ans);
}
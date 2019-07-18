#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 51000
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define int long long
struct rec {
	int op, x, y;
	long long z;
} q[MAXN << 2], lq[MAXN << 2], rq[MAXN << 2];
int n, m, t, ans[MAXN], id, op, cnt;
struct Segtree {
	int a[MAXN], b[MAXN << 2], f[MAXN << 2], lazy[MAXN << 2];
	void pd(int p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	void fa(int l, int r, int k, int p) {
		lazy[p] += k;
		b[p] += (r - l + 1) * k;
	}
	void pushd(int p, int l, int r) {
		if (f[p]) {
			f[p] = 0;
			lazy[ls(p)] = lazy[rs(p)] = b[ls(p)] = b[rs(p)] = 0;
			f[ls(p)] = f[rs(p)] = 1;
		}
		if (lazy[p]) {
			int m = (l + r) >> 1;
			fa(l, m, lazy[p], ls(p));
			fa(m + 1, r, lazy[p], rs(p));
			lazy[p] = 0;
		}
	}
	void chg(int x, int y, int l, int r, int k, int p) {
		if (x <= l && y >= r) {
			lazy[p] += k;
			b[p] += (r - l + 1) * k;
			return;
		}
		pushd(p, l, r);
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
		pushd(p, l, r);
		int m = (l + r) >> 1;
		if (x <= m) s += ask(x, y, l, m, ls(p));
		if (y > m) s += ask(x, y, m + 1, r, rs(p));
		return s;
	}
}tr;
void solve(int lval, int rval, int st, int ed) {
	if (st > ed) return;
	if (lval == rval) {
		for (int i = st; i <= ed; i++) {
			if (q[i].op > 0) ans[q[i].op] = lval;
		}
		return;
	}
	int mid = (lval + rval) >> 1;
	int lt = 0, rt = 0;
	tr.f[1] = 1;
	tr.b[1] = tr.lazy[1] = 0;
	for (int i = st; i <= ed; i++) {
		if (q[i].op == -1) {
			if (q[i].z <= mid) lq[++lt] = q[i];
			else tr.chg(q[i].x, q[i].y, 1, n, 1, 1), rq[++rt] = q[i];
		}
		if (q[i].op > 0){
			int cnt = tr.ask(q[i].x, q[i].y, 1, n, 1);
			// printf("%d\n", cnt);
			if (cnt >= q[i].z) rq[++rt] = q[i];
			else q[i].z -= cnt, lq[++lt] = q[i];
		}
	}
	for (int i = 1; i <= lt; i++) q[st + i - 1] = lq[i];
	for (int i = 1; i <= rt; i++) q[st + lt + i - 1] = rq[i];
	solve(lval, mid, st, st + lt - 1);
	solve(mid + 1, rval, st + lt, ed);
}
signed main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &op, &q[i].x, &q[i].y);
		std::cin >> q[i].z;
		if (op == 1) {
			q[i].op = -1;
		}
		else {
			q[i].op = ++cnt;
		}
	}
	solve(-n, n, 1, m);
	for (int i = 1; i <= cnt; i++) {
		// printf("%d ", tr.ask(1, 1, 1, n, 1));
		printf("%lld\n", ans[i]);
	}
}
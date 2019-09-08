#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 3000010
#define INF 2000000000
struct rec {
	int op, x, y, z;
}q[MAXN << 1], lq[MAXN << 1], rq[MAXN << 1];
int n, m, t, c[MAXN], ans[MAXN], a[MAXN], b[MAXN];
int ask(int x) {
	int y = 0;
	for (; x; x -= x & -x) y += c[x];
	return y;
}
void change(int x, int y) {
	for (; x <= n; x += x & -x) c[x] += y;
}
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
	for (int i = st; i <= ed; i++) {
		if (q[i].op == 0) {
			if (q[i].y <= mid) change(q[i].x, 1), lq[++lt] = q[i];
			else rq[++rt] = q[i];
		}
		else {
			int cnt = ask(q[i].y) - ask(q[i].x - 1);
			if (cnt >= q[i].z) lq[++lt] = q[i];
			else q[i].z -= cnt, rq[++rt] = q[i];
		}
	}
	for (int i = ed; i >= st; i--) {
		if (q[i].op == 0 && q[i].y <= mid) change(q[i].x, -1);
	}
	for (int i = 1; i <= lt; i++) q[st + i - 1] = lq[i];
	for (int i = 1; i <= rt; i++) q[st + lt + i - 1] = rq[i];
	solve(lval, mid, st, st + lt - 1);
	solve(mid + 1, rval, st + lt, ed);
}
int l, r, k;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int val;
		scanf("%d", &val);
		a[i] = b[i] = val;
	}
	std::sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; i++) {
		a[i] = std::lower_bound(b + 1, b + 1 + n, a[i]) - b;
	}
	for (int i = 1; i <= n; i++) {
		q[++t].op = 0, q[t].x = i, q[t].y = a[i];
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &l, &r, &k);
		q[++t].op = i, q[t].x = l, q[t].y = r, q[t].z = k;
	}
	solve(1, n, 1, t);
	for (int i = 1; i <= m; i++) {
		printf("%d\n", b[ans[i]]);
	}
}
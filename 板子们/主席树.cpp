#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN (10001000 << 1)
struct moha_tree {
	int a[MAXN], lsn[MAXN], rsn[MAXN], b[MAXN];
	int tot;
	int build(int l, int r) {
		int p = ++tot;
		if (l == r) {
			scanf("%d", &a[p]);
			return tot;
		}
		int m = (l + r) >> 1;
		lsn[p] = build(l, m);
		rsn[p] = build(m + 1, r);
		return p;
	}
	int upd(int l, int r, int pa, int k, int x) {
		int p = ++tot;
		if (l == r) {
			a[p] = x;
			return p;
		}
		lsn[p] = lsn[pa];
		rsn[p] = rsn[pa];
		int m = (l + r) >> 1;
		if (x <= m) lsn[p] = upd(l, m, lsn[pa], k, x);
		else rsn[p] = upd(m + 1, r, rsn[pa], k, x);
		return p;
	}
	void ask(int l, int r, int pa, int x) {
		if (l == r) {
			printf("%d\n", a[pa]);
			return;
		}
		int m = (l + r) >> 1;
		if (x <= m) ask(l, m, lsn[pa], x);
		else ask(m + 1, r, rsn[pa], x);
	}
}tr;
int n, m, op, x, k, y;
int main() {
	tr.tot = 0;
	scanf("%d%d", &n, &m);
	tr.build(1, n);
	tr.b[0] = 1;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &k, &op, &x);
		if (op == 1) {
			scanf("%d", &y);
			tr.b[i] = tr.upd(1, n, tr.b[k], x, y);
		}
		else {
			tr.b[i] = tr.b[k];
			tr.ask(1, n, tr.b[k], x);
		}
	}
}
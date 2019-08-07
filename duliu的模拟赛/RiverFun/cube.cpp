#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 100010
namespace oned {
	struct rec {
		int op, x, y, z;
	}q[MAXN << 1], lq[MAXN << 1], rq[MAXN << 1];
	int n, m, t, c[MAXN], ans[MAXN];
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
}
namespace twod {
	struct rec {
		int op, x1, y1, x2, y2, z;
	}q[MAXN << 1], lq[MAXN << 1], rq[MAXN << 1];
	int n, m, t, c[316][316], ans[MAXN];
	int ask(int x, int y) {
		int k = 0;
		for (int i = x; i; i -= i & -i) {
			for (int j = y; j; j -= j & -j) k += c[i][j];
		}
		return k;
	}
	void change(int x, int y, int k) {
		for (int i = x; i <= n; i += i & -i) {
			for (int j = y; j <= n; j += j & -j) c[i][j] += k;
		}
	}
	int _ask(int x1, int y1, int x2, int y2) {
		int res = 0;
		res += ask(x2, y2);
		res -= ask(x1 - 1, y2);
		res -= ask(x2, y1 - 1);
		res += ask(x1 - 1, y1 - 1);
		return res;
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
				if (q[i].z <= mid) change(q[i].x1, q[i].y1, 1), lq[++lt] = q[i];
				else rq[++rt] = q[i];
			}
			else {
				int cnt = _ask(q[i].x1, q[i].y1, q[i].x2, q[i].y2);
				if (cnt >= q[i].z) lq[++lt] = q[i];
				else q[i].z -= cnt, rq[++rt] = q[i];
			}
		}
//		puts("");
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				printf("%d ", c[i][j]);
//			}
//			puts("");
//		}
//		puts("-------");
		for (int i = ed; i >= st; i--) {
			if (q[i].op == 0 && q[i].z <= mid) change(q[i].x1, q[i].y1, -1);
		}
		for (int i = 1; i <= lt; i++) q[st + i - 1] = lq[i];
		for (int i = 1; i <= rt; i++) q[st + lt + i - 1] = rq[i];
		solve(lval, mid, st, st + lt - 1);
		solve(mid + 1, rval, st + lt, ed);
	}
}
int w;
int main() {
	freopen("cube.in", "r", stdin);
	freopen("cube.out", "w", stdout);
	scanf("%d", &w);
	if (w == 1) {
		using namespace oned;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			t++;
			scanf("%d", &q[t].y);
			q[t].x = i;
			q[t].op = 0;
		}
		for (int i = 1; i <= m; i++) {
			t++;
			scanf("%d%d%d", &q[t].x, &q[t].y, &q[t].z);
			q[t].op = i;
		}
		solve(0, 998244353, 1, t);
		for (int i = 1; i <= m; i++) {
			printf("%d\n", ans[i]);
		}
	}
	if (w == 2) {
		using namespace twod;
		t = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				t++;
				scanf("%d", &q[t].z);
				q[t].x1 = i, q[t].y1 = j;
				q[t].op = 0;
			}
		}
		for (int i = 1; i <= m; i++) {
			t++;
			scanf("%d%d%d%d%d", &q[t].x1, &q[t].y1, &q[t].x2, &q[t].y2, &q[t].z);
			q[t].op = i;
		}
		solve(0, 998244353, 1, t);
		for (int i = 1; i <= m; i++) {
			printf("%d\n", ans[i]);
		}
	}
}
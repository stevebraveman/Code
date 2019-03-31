#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
int n, m, x, y, z = 0;
char op[5];
struct nd {
	int b, lazy, lc, rc;
}tr[MAXN << 2];
struct Segtree {
	int a[MAXN];
	void pd(int p) {
		tr[p].b = (tr[rs(p)].lc == tr[ls(p)].rc ? -1 : 0) + tr[ls(p)].b + tr[rs(p)].b;
		tr[p].lc = tr[ls(p)].lc;
		tr[p].rc = tr[rs(p)].rc;
	}
	void build(int l, int r, int p) {
		tr[p].lazy = 0;
		if (l == r) {
			tr[p].b = 1;
			tr[p].lc = tr[p].rc = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	void f(int l, int r, int k, int p) {
		tr[p].lazy = tr[p].lc = tr[p].rc = k;
		tr[p].b = 1;
	}
	void pushd(int l, int r, int p) {
		if (tr[p].lazy) {
			int m = (l + r) >> 1;
			f(l, m, tr[p].lazy, ls(p));
			f(m + 1, r, tr[p].lazy, rs(p));
			tr[p].lazy = 0;
		}
	}
	void updated(int x, int y, int l, int r, int p, int k) {
		if (x <= l && y >= r) {
			tr[p].b = 1;
			tr[p].lc = tr[p].rc = tr[p].lazy = k;
			return;
		}
		int m = (l + r) >> 1;
		pushd(l, r, p);
		if (x <= m) updated(x, y, l, m, ls(p), k);
		if (y > m) updated(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	nd ask(int x, int y, int l, int r, int p) {
		if (x <= l && y >= r) {
			return tr[p];
		}
		int m = (l + r) >> 1;
		pushd(l, r, p);
		if(x <= m && y > m) {
			nd a = ask(x, y, l, m, ls(p));
			nd b = ask(x, y, m + 1, r, rs(p));
			nd c;
			c.lc = a.lc;
			c.rc = b.rc;
			c.b = a.b + b.b + (a.rc == b.lc ? -1 : 0);
			return c;
		}
		if (x <= m) return ask(x, y, l, m, ls(p));
		if (y > m) return ask(x, y, m + 1, r, rs(p));
	}
}tree;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		
	}
}
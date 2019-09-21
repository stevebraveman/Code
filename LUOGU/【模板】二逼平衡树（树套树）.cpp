#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#define MAXN 2000020
#define INF 0x7fffffff
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Treap {
	int l, r;
	int val, dat;
	int cnt, size;
}a[MAXN];
int tot, n, m;
int New(int val) {
	a[++tot].val = val;
	a[tot].dat = rand();
	a[tot].cnt = a[tot].size = 1;
	return tot;
}
void update(int p) {
	a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
}
int FindR(int p, int val) {
	// printf("%d %d %d\n", p, a[p].val, val);
	if (p == 0) return 0;
	if (val == a[p].val) return a[a[p].l].size;
	else if (val < a[p].val) return FindR(a[p].l, val);
	else return FindR(a[p].r, val) + a[a[p].l].size + a[p].cnt;
}
void zig(int &p) {
	int q = a[p].l;
	a[p].l = a[q].r, a[q].r = p, p = q;
	update(a[p].r), update(p);
}
void zag(int &p) {
	int q = a[p].r;
	a[p].r = a[q].l, a[q].l = p, p = q;
	update(a[p].l), update(p);
}
void insert(int &p, int val) {
	if (p == 0) {
		p = New(val);
		return;
	}
	if (val == a[p].val) {
		a[p].cnt++, update(p);
		return;
	}
	if (val < a[p].val) {
		insert(a[p].l, val);
		if (a[p].dat < a[a[p].l].dat) zig(p);
	}
	else {
		insert(a[p].r, val);
		if (a[p].dat < a[a[p].r].dat) zag(p);
	}
	update(p);
}
int Pre(int p, int val) {
	if (!p) {
		return -INF;
	}
	if (a[p].val >= val) {
		return Pre(a[p].l, val);
	}
	else {
		return max(a[p].val, Pre(a[p].r, val));
	}
}
int Next(int p, int val) {
	if (!p) {
		return INF;
	}
	if (a[p].val <= val) {
		return Next(a[p].r, val);
	}
	else {
		return min(a[p].val, Next(a[p].l, val));
	}
}
void Remove(int &p, int val) {
	if (p == 0) return;
	if (val == a[p].val) {
		if (a[p].cnt > 1) {
			a[p].cnt--, update(p);
			return;
		}
		if (a[p].l || a[p].r) {
			if (a[p].r == 0 || a[a[p].l].dat > a[a[p].r].dat)
				zig(p), Remove(a[p].r, val);
			else
				zag(p), Remove(a[p].l, val);
			update(p);
		}
		else p = 0;
		return;
	}
	val < a[p].val ? Remove(a[p].l, val) : Remove(a[p].r, val);
	update(p);
}
struct Segtree {
	int a[MAXN], b[MAXN], rt[MAXN];
	void build(int l, int r, int p) {
		for (int i = l; i <= r; i++) {
			insert(rt[p], a[i]);
		}
		if (l != r) {
			int m = (l + r) >> 1;
			build(l, m, ls(p));
			build(m + 1, r, rs(p));
		}
	}
	void change(int x, int l, int r, int k, int p) {
		Remove(rt[p], a[x]);
		insert(rt[p], k);
		if (l == r) {
			return;
		}
		int m = (l + r) >> 1;
		if (x <= m) change(x, l, m, k, ls(p));
		else change(x, m + 1, r, k, rs(p));
	}
	int RgRk(int x, int y, int l, int r, int k, int p) {
		if (l > y || r < x) {
			return 0;
		}
		// printf("%d\n", p);
		if (l >= x && y >= r) {
			return FindR(rt[p], k);
		}
		else {
			int m = (l + r) >> 1;
			return RgRk(x, y, l, m, k, ls(p)) + RgRk(x, y, m + 1, r, k, rs(p));
		}
	}
	int RgKth(int x, int y, int l, int r, int k, int p) {
		int ql = 0, qr = 100000000;
		while (ql < qr) {
			int m = (ql + qr + 1) >> 1;
			if (RgRk(x, y, 1, n, m, 1) < k) {
				ql = m;
			}
			else qr = m - 1;
		}
		return qr;
	}
	int RgPre(int x, int y, int l, int r, int k, int p) {
		if (l > y || r < x) {
			return -INF;
		}
		if (l >= x && y >= r) {
			return Pre(rt[p], k);
		}
		else {
			int m = (l + r) >> 1;
			return max(RgPre(x, y, l, m, k, ls(p)), RgPre(x, y, m + 1, r, k, rs(p)));
		}
	}
	int RgNext(int x, int y, int l, int r, int k, int p) {
		if (l > y || r < x) {
			return INF;
		}
		if (l >= x && y >= r) {
			return Next(rt[p], k);
		}
		else {
			int m = (l + r) >> 1;
			return min(RgNext(x, y, l, m, k, ls(p)), RgNext(x, y, m + 1, r, k, rs(p)));
		}
	}
}tr;
int op, l, r, k;
int main() {
	srand(time(NULL));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tr.a[i]);
	}
	tr.build(1, n, 1);
	while (m--) {
		scanf("%d", &op);
		switch (op) {
			case 1: {
				scanf("%d%d%d", &l, &r, &k);
				printf("%d\n", tr.RgRk(l, r, 1, n, k, 1) + 1);
				break;
			}
			case 2: {
				scanf("%d%d%d", &l, &r, &k);
				printf("%d\n", tr.RgKth(l, r, 1, n, k, 1));
				break;
			}
			case 3: {
				scanf("%d%d", &l, &r);
				tr.change(l, 1, n, r, 1);
				tr.a[l] = r;
				break;
			}
			case 4: {
				scanf("%d%d%d", &l, &r, &k);
				printf("%d\n", tr.RgPre(l, r, 1, n, k, 1));
				break;
			}
			case 5: {
				scanf("%d%d%d", &l, &r, &k);
				printf("%d\n", tr.RgNext(l, r, 1, n, k, 1));
				break;
			}
		}
	}
}
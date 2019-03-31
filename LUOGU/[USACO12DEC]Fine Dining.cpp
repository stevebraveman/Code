#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define INF 192608170
#define MAXN 1001000
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Segtree {
	int a[MAXN], b[MAXN << 1];
	void pd(int p) {
		b[p] = min(b[ls(p)], b[rs(p)]);
	}
	void build(int p, int l, int r) {
		if (l == r) {
			b[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(ls(p), l, m);
		build(rs(p), m + 1, r);
		pd(p);
	}
	int query(int x, int y, int l, int r, int p) {
		int ans = INF;
		if (x <= l &&y >= r) {
			return b[p];
		}
		int m = (l + r) >> 1;
		if (x <= m) ans = min(query(x, y, l, m, ls(p)), ans);
		if (y > m) ans = min(query(x, y, m + 1, r, rs(p)), ans);
		return ans;
	}
} tree;
int n, m, l, r;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tree.a[i]);
	}
	tree.build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &l, &r);
		printf("%d\n", tree.query(l, r, 1, n, 1));
	}
	return 0;
}
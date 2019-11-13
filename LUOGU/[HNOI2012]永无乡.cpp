#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#define MAXN 2000010
struct Treap {
	int v, dat, id;
	int cnt, siz;
	int l, r;
}a[MAXN];
int tot, x, n, y, m, q, fa[MAXN], rt[MAXN];
int New(int val, int id) {
	tot++;
	a[tot].v = val;
	a[tot].id = id;
	a[tot].dat = rand();
	a[tot].cnt = a[tot].siz = 1;
	return tot;
}
void update(int p) {
	a[p].siz = a[p].cnt + a[a[p].l].siz + a[a[p].r].siz;
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
void insert(int &p, int val, int id) {
	if (!p) {
		// puts("OK");
		p = New(val, id);
		// printf("%d %d %d\n", p, val, id);
		return;
	}
	if (val == a[p].v) {
		a[p].cnt++, update(p);
		return;
	}
	if (val < a[p].v) {
		insert(a[p].l, val, id);
		if (a[p].dat < a[a[p].l].dat) zig(p);
	}
	else {
		insert(a[p].r, val, id);
		if (a[p].dat < a[a[p].r].dat) zag(p);
	}
	// puts("rotate");
	update(p);
}
int Findk(int p, int k) {
	if (p == 0) return 0;
	if (a[a[p].l].siz >= k) return Findk(a[p].l, k);
	if (a[a[p].l].siz + a[p].cnt >= k) return a[p].id;
	return Findk(a[p].r, k - a[a[p].l].siz - a[p].cnt);
}
void merge(int x, int y) {
	if (!y) return;
	// printf("%d", y);
	insert(rt[x], a[y].v, a[y].id);
	merge(x, a[y].l);
	merge(x, a[y].r);
}
char op[5];
int find(int x) {
	if (x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}
int main() {
	srand(time(NULL));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		fa[i] = i;
		insert(rt[i], x, i);
	}
	// puts("");
	while (m--) {
		scanf("%d%d", &x, &y);
		int _x = find(x);
		int _y = find(y);
		if (_x == _y) continue;
		if (a[rt[_x]].siz < a[rt[_y]].siz) std::swap(_x, _y);
		fa[_y] = _x;
		merge(_x, rt[_y]);
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%s", op);
		if (op[0] == 'B') {
			scanf("%d%d", &x, &y);
			if (!x || !y) continue;
			int _x = find(x), _y = find(y);
			if (_x == _y) continue;
			// printf("%d %d %d %d\n", _x, _y, rt[_x], rt[_y]);
			if (a[rt[_x]].siz < a[rt[_y]].siz) std::swap(_x, _y);
			fa[_y] = _x;
			merge(_x, rt[_y]);
			// puts("");
		}
		else {
			scanf("%d%d", &x, &y);
			int _x = find(x);
			// printf("%d %d ", _x, a[rt[_x]].siz);
			int ans = Findk(rt[_x], y);
			if (!ans) {
				puts("-1");
			}
			else printf("%d\n", ans);
		}
		// for (int i = 1; i <= n; i++) {
		// 	printf("%d ", a[rt[i]].siz);
		// }
		// puts("");
		// puts("----");
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1001000
struct Treap {
	int v, dat;
	int cnt, siz;
	int l, r;
}a[MAXN];
int tot, fa[MAXN], rt[MAXN];
int New(int val) {
	tot++;
	a[tot].v = val;
	a[tot].dat = rand();
	a[tot].cnt = a[tot].siz = 1;
}
void update(int p) {
	a[p].siz = a[p].cnt + a[a[p].l].siz + a[a[p].r].siz;
}
void zig(int &p) {
	int q = a[p].l;
	a[p].l = a[q].r, a[p].r = p, p = q;
	update(a[p].r), update(p);
}
void zag(int &p) {
	int q = a[p].r;
	a[p].r = a[q].l, a[p].l = p, p = q;
	update(a[p].l), update(p);
}
void insert(int &p, int val) {
	if (!p) {
		p = New(val);
		return;
	}
	if (val == a[p].val) {
		a[p].cnt++;
		update(p);
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
int find(int x) {
	if (x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}
void merge(int &x, int y) {
	if (!y) return;
	insert(x, a[y].val);
	merge(x, a[y].r);
	merge(x, a[y].l);
}
int x, y, n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		insert(rt[x], i);
	}
}
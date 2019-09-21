#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2000010
struct Treap {
	int l, r;
	int val, dat;
	int cnt, size;
}a[MAXN];
int tot, root, n, INF = 0x7fffffff;
int New(int val) {
	a[++tot].val = val;
	a[tot].dat = rand();
	a[tot].cnt = a[tot].size = 1;
	return tot;
}
void update(int p) {
	a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
}
void Build() {
	New(-INF), New(INF);
	root = 1, a[1].r = 2;
	update(root);
}
int FindN(int p, int r) {
	if (p == 0) return INF;
	if (a[a[p].l].size >= r) return FindN(a[p].l, r);
	if (a[a[p].l].size + a[p].cnt >= r) return a[p].val;
	return FindN(a[p].r, r - a[a[p].l].size - a[p].cnt);
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
int op, x, u[MAXN], m, vis[MAXN];
int main() {
	Build();
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &u[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &op);
		vis[op]++;
	}
	for (int i = 1; i <= n; i++) {
		insert(root, u[i]);
		while (vis[i]) {
			printf("%d\n", FindN(root, (++x) + 1));
			vis[i]--;
		}
	}
}
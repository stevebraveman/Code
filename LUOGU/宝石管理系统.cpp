#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#define MAXN 200020
#define INF 0x7fffffff
struct Treap {
	int l, r;
	int dat, val;
	int size, cnt;
}a[MAXN];
int n, m, x, op, tot, root;
int New(int val) {
	a[++tot].dat = rand();
	a[tot].val = val;
	a[tot].cnt = a[tot].size = 1;
	return tot;
}
void update(int p) {
	a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
}
int Kth(int p, int val) {
	if (p == 0) return INF;
	if (a[a[p].r].size >= val) return Kth(a[p].r, val);
	if (a[a[p].r].size + a[p].cnt >= val) return a[p].val;
	return Kth(a[p].l, val - a[a[p].r].size - a[p].cnt);
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
int main() {
	srand(time(NULL));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		insert(root, x);
	}
	while (m--) {
		scanf("%d%d", &op, &x);
		if (op == 1) {
			printf("%d\n", Kth(root, x));
		}
		else {
			insert(root, x);
		}
	}
}
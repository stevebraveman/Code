#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <map>
#define MAXN 100010
bool p1;
std::map <int, int> h;
struct Treap {
	int l, r;
	int dat, val;
	int size, cnt;
} a[MAXN];
int root, n, m, w, c, tot, ans, ansm;
bool p2;
int New(int val) {
	a[++tot].val = val;
	a[tot].dat = rand();
	a[tot].cnt = a[tot].size = 1;
	return tot;
}
void update(int p) {
	a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
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
void del(int &p, int val) {
	if (p == 0) return;
	if (val == a[p].val) {
		if (a[p].cnt > 1) {
			a[p].cnt--, update(p);
			return;
		}
		if (a[p].l || a[p].r) {
			if (a[p].r == 0 || a[a[p].l].dat > a[a[p].r].dat)
				zig(p), del(a[p].r, val);
			else
				zag(p), del(a[p].l, val);
			update(p);
		}
		else p = 0;
		return;
	}
	val < a[p].val ? del(a[p].l, val) : del(a[p].r, val);
	update(p);
}
void Min(int p) {
	if (a[p].l == 0) ansm -= a[p].val, ans -= h[a[p].val], h[a[p].val] = 0, del(root, a[p].val);
	else Min(a[p].l);
}
void Max(int p) {
	if (a[p].r == 0) ansm -= a[p].val, ans -= h[a[p].val], h[a[p].val] = 0, del(root, a[p].val);
	else Max(a[p].r);
}
int op;
int main() {
	srand(time(NULL));
	while (1) {
		scanf("%d", &op);
		if (op == -1) break;
		if (op == 1) {
			scanf("%d%d", &w, &c);
			if (h[c]) continue;
			ansm += c;
			h[c] = w;
			ans += w;
			insert(root, c);
		}
		if (op == 3) {
			Min(root);
		}
		if (op == 2) {
			Max(root);
		}
	}
	printf("%d %d", ans, ansm);
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
bool p1;
struct Treap {
	int l, r;
	int val, dat;
	int cnt, size;
}a[MAXN];
int tot, root, n, INF = 19260817, mina, sum, s, num;
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
int Pre(int val) {
	int ans = 1;
	int p = root;
	while (p) {
		if (val == a[p].val) {
			ans = p;
			break;
		}
		if (a[p].val < val && a[p].val > a[ans].val) ans = p;
		p = val < a[p].val ? a[p].l : a[p].r;
	}
	return a[ans].val;
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
char op;
int x;
int main() {
	Build();
	scanf("%d%d", &n, &mina);
	while (n--) {
		std::cin >> op;
		scanf("%d", &x);
		if (op == 'I') {
			if (x - sum >= mina) insert(root, x - sum), num++, s++;
		}
		if (op == 'A') mina -= x, sum += x;
		if (op == 'S') {
			mina += x;
			sum -= x;
			int g = mina - 1, f;
			while (Pre(g) != -INF) {
				f = g;
				g = Pre(f);
				Remove(root, Pre(f));
				num--;
			}
		}
		if (op == 'F') {
			if (num < x) puts("-1");
			else printf("%d\n", FindN(root, num - x + 2) + sum);
		}
	}
	printf("%d\n", s - num);
}
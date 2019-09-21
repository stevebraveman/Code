#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100010
int bl[MAXN], a[MAXN];
struct que {
	int l, r, t, id;
}q[MAXN];
struct modi {
	int x, y;
}c[MAXN];
int num[MAXN * 10], tot = 0, l, r, n, m, ans[MAXN];
bool cmp(que a, que b) {
	if (bl[a.l] != bl[b.l]) return a.l < b.l;
	if (bl[a.r] != bl[b.r]) return a.r < b.r;
	return a.t < b.t;
}
void add(int x) {
	if (!num[x]++) tot++;
}
void del(int x) {
	if (!--num[x]) tot--;
}
void modify(int x) {
	if (c[x].x >= l && c[x].x <= r) {
		del(a[c[x].x]);
		add(c[x].y);
	}
	std::swap(c[x].y, a[c[x].x]);
}
char op[5];
int qn, cn, sq, t;
int main() {
	scanf("%d%d", &n, &m);
	sq  = pow(n, 0.66);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		bl[i] = (i - 1) / sq + 1;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%s%d%d", op, &l, &r);
		if (op[0] == 'Q') {
			q[++qn].l = l;
			q[qn].r = r;
			q[qn].t = cn;
			q[qn].id = qn;
		}
		else {
			c[++cn].x = l;
			c[cn].y = r;
		}
	}
	std::sort(q + 1, q + 1 + qn, cmp);
	l = r = t = 0;
	for (int i = 1; i <= qn; i++) {
		while (l < q[i].l) del(a[l++]);
		while (l > q[i].l) add(a[--l]);
		while (r < q[i].r) add(a[++r]);
		while (r > q[i].r) del(a[r--]);
		while (t < q[i].t) modify(++t);
		while (t > q[i].t) modify(t--);
		ans[q[i].id] = tot;
	}
	for (int i = 1; i <= qn; i++) {
		printf("%d\n", ans[i]);
	}
}
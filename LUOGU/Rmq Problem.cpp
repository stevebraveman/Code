#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <tr1/unordered_map>
#define MAXN 1000010
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct ques {
	int l, r, id, ans;
}q[MAXN];
int sq, a[MAXN], b[MAXN], n, m, l, r, tot = 0, h[MAXN];
bool cmp(ques a, ques c) {
	return b[a.l] == b[c.l] ? a.r < c.r : a.l < c.l;
}
bool rep(ques a, ques b) {
	return a.id < b.id;
}
void count(int x, int y) {
	h[a[x]] += y;
	if (h[a[x]] == 0 && a[x] < tot) {
		tot = a[x];
		return;
	}
	if (a[x] == tot) for (tot; h[tot]; tot++);
}
int main() {
	scanf("%d%d", &n, &m);
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = (i - 1) / sq + 1;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	std::sort(q + 1, q + 1 + m, cmp);
	l = 1;
	for (int i = 1; i <= m; i++) {
		while (l < q[i].l) count(l, -1), l++;
		while (l > q[i].l) count(l - 1, 1), l--;
		while (r < q[i].r) count(r + 1, 1), r++;
		while (r > q[i].r) count(r, -1), r--;
		q[i].ans = tot;
	}
	std::sort(q + 1, q + 1 + m, rep);
	for (int i = 1; i <= m; i++) {
		printf("%d\n", q[i].ans);
	}
	return 0;
}
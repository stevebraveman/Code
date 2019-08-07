#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAXN 100010
struct que {
	int l, r, id;
}q[MAXN];
int a[MAXN], b[MAXN], sq, num[MAXN], tot, n, m, l, r, ans[MAXN];
bool cmp(que a, que c) {
	if (b[a.l] == b[c.l]) return a.r < c.r;
	else return a.l < c.l;
}
void add(int x) {
	num[x]++;
	if (num[x] == 1) tot++;
}
void del(int x) {
	num[x]--;
	if (num[x] == 0) tot--;
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
	for (int i = 1; i <= m; i++) {
		while (l < q[i].l) del(a[l++]);
		while (l > q[i].l) add(a[--l]);
		while (r < q[i].r) add(a[++r]);
		while (r > q[i].r) del(a[r--]);
		ans[q[i].id] = tot == r - l + 1;
	}
	for (int i = 1; i <= m; i++) {
		puts(ans[i] ? "Yes" : "No");
	}
	return 0;
}
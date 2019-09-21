#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100010
#define int long long
struct ques {
	int l, r, id;
}q[MAXN];
int sq, a[MAXN], b[MAXN], n, m, l, r, c[MAXN], p[MAXN], k, ans[MAXN], tot;
bool cmp(ques a, ques c) {
	return b[a.l] == b[c.l] ? a.r < c.r : a.l < c.l;
}
void count(int x, int y) {
	tot -= c[a[x]] * c[a[x]];
	c[a[x]] += y;
	tot += c[a[x]] * c[a[x]];
}
signed main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		b[i] = (i - 1) / sq + 1;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	std::sort(q + 1, q + 1 + m, cmp);
	l = 1;
	r = 0;
	for (int i = 1; i <= m; i++) {
		while (l < q[i].l) count(l, -1), l++;
		while (l > q[i].l) count(l - 1, 1), l--;
		while (r < q[i].r) count(r + 1, 1), r++;
		while (r > q[i].r) count(r, -1), r--;
		ans[q[i].id] = tot;
	}
	for (int i = 1; i <= m; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}
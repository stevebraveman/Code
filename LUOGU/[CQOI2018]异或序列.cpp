#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 2000010
#define sqr(x) ((x) * (x))
struct ques {
	int l, r, id, a;
}q[MAXN];
int sq, a[MAXN], b[MAXN], n, m, l, r, prex[MAXN], buk[MAXN], k;
int ans[MAXN], tot;
bool cmp(ques a, ques c) {
	return b[a.l] == b[c.l] ? a.r < c.r : a.l < c.l;
}
bool replace(ques a, ques b) {
	return a.id < b.id;
}
void count(int x, int y) {
	if (y == -1) {
		buk[prex[x]]--;
		tot -= buk[prex[x] ^ k];
		return;
	}
	tot += buk[prex[x] ^ k];
	buk[prex[x]]++;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		prex[i] = prex[i - 1] ^ a[i];
		b[i] = (i - 1) / sq + 1;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].l--;
		q[i].id = i;
	}
	l = 1;
	std::sort(q + 1, q + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		while (l < q[i].l) count(l, -1), l++;
		while (l > q[i].l) count(l - 1, 1), l--;
		while (r < q[i].r) count(r + 1, 1), r++;
		while (r > q[i].r) count(r, -1), r--;
		q[i].a = tot;
	}
	std::sort(q + 1, q + 1 + m, replace);
	for (int i = 1; i <= m; i++) {
		printf("%d\n", q[i].a);
	}
}
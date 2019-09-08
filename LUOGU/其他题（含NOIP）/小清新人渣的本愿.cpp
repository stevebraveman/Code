#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
struct ques {
	int l, r, id, a, op;
}q[MAXN];
int sq, a[MAXN], b[MAXN], n, m, aw[MAXN << 2], tot1, tot2, tot3;
int l1 = 1, r1 = 0, l2 = 1, r2 = 0, l3 = 1, r3 = 0, ans1[MAXN << 2], ans2[MAXN << 2], ans3[MAXN << 2];
bool cmp(ques a, ques c) {
	return (a.op < b.op) && (b[a.l] == b[c.l] ? a.r < c.r : a.l < c.l);
}
bool replace(ques a, ques b) {
	return a.id < b.id;
}
void count1(int x, int y, int k) {
	tot1 += y * ans1[a[x] + k];
	ans1[a[x]] += y;
}
void count2(int x, int y, int k) {
	tot2 += y * ans2[a[x] - k];
	ans2[a[x]] += y;
}
void count3(int x, int y, int k) {
	tot3 += x % k == 0 ? y * ans3[a[x] / k] : 0;
	ans3[a[x]] += y;
}
int main() {
	scanf("%d%d", &n, &m);
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = (i - 1) / sq + 1;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &q[i].op, &q[i].l, &q[i].r, &q[i].a);
		q[i].id = i;
	}
	std::sort(q + 1, q + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		if (q[i].op == 1) {
			while (l1 < q[i].l) count1(l1, -1, q[i].a), l1++;
			while (l1 > q[i].l) count1(l1 - 1, 1, q[i].a), l1--;
			while (r1 < q[i].r) count1(r1 + 1, 1, q[i].a), r1++;
			while (r1 > q[i].r) count1(r1, -1, q[i].a), r1--;
			aw[q[i].id] = tot1;
		}
		if (q[i].op == 2) {
			while (l2 < q[i].l) count2(l2, -1, q[i].a), l2++;
			while (l2 > q[i].l) count2(l2 - 1, 1, q[i].a), l2--;
			while (r2 < q[i].r) count2(r2 + 1, 1, q[i].a), r2++;
			while (r2 > q[i].r) count2(r2, -1, q[i].a), r2--;
			aw[q[i].id] = tot2;
		}
		if (q[i].op == 3) {
			while (l3 < q[i].l) count3(l3, -1, q[i].a), l3++;
			while (l3 > q[i].l) count3(l3 - 1, 1, q[i].a), l3--;
			while (r3 < q[i].r) count3(r3 + 1, 1, q[i].a), r3++;
			while (r3 > q[i].r) count3(r3, -1, q[i].a), r3--;
			aw[q[i].id] = tot3;
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%d", aw[i]);
	}
	return 0;
}
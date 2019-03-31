#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 1000010
#define ll long long
#define sqr(x) ((x) * (x))
template<typename Tp>
Tp gcd(Tp a, Tp b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
struct ques {
	int l, r, id;
	ll a1, a2;
}q[MAXN];
int sq, a[MAXN], b[MAXN], n, m, l, r, _gcd_;
ll ans[MAXN], tot;
bool cmp(ques a, ques c) {
	return b[a.l] == b[c.l] ? a.r < c.r : a.l < c.l;
}
bool replace(ques a, ques b) {
	return a.id < b.id;
}
void count(int x, int y) {
	tot -= sqr(ans[a[x]]);
	ans[a[x]] += (ll)y;
	tot += sqr(ans[a[x]]);
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
	l = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		while (l < q[i].l) count(l, -1), l++;
		while (l > q[i].l) count(l - 1, 1), l--;
		while (r < q[i].r) count(r + 1, 1), r++;
		while (r > q[i].r) count(r, -1), r--;
		if (q[i].l == q[i].r) {
			q[i].a1 = 0;
			q[i].a2 = 1;
			continue;
		}
		q[i].a1 = tot - (ll)(q[i].r - q[i].l + 1);
		q[i].a2 = 1LL * (q[i].r - q[i].l + 1) * (q[i].r - q[i].l);
		_gcd_ = gcd(q[i].a1, q[i].a2);
		q[i].a1 = q[i].a1 / _gcd_;
		q[i].a2 = q[i].a2 / _gcd_;
	}
	std::sort(q + 1, q + 1 + m, replace);
	for (int i = 1; i <= m; i++) {
		printf("%lld/%lld\n", q[i].a1, q[i].a2);
	}
	return 0;
}
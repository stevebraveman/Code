#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAXN 200010
int n, m, a[MAXN], maxa, b[MAXN], ans;
long long tot;
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		maxa = std::max(a[i], maxa);
	}
	for (int i = 1; i <= n; i++) {
		b[i] = maxa - a[i];
	}
	std::sort(b + 1, b + 1 + n, cmp);
	ans = b[1];
	for (int i = 2; i <= n; i++) {
		if (!b[i]) continue;
		ans = gcd(ans, b[i]);
	}
	for (int i = 1; i <= n; i++) {
		tot += 1LL * (b[i] / ans);
	}
	printf("%I64d %d", tot, ans);
}
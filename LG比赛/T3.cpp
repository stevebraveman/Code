#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 10100
#define ll long long
#define LIM 90000000
ll x, y, a, b, p, ans, t, li;
int main() {
	scanf("%lld%lld", &a, &b);
	if ((a / 2) * (a / 2) == b && !(a & 1)) {
		puts("inf");
		return 0;
	}
	li = std::max(a / 2, (ll)sqrt(b) + 1);
	for (register int i = 0; i <= li; i++) {
		p = 1LL * i * i - b;
		t = a - 1LL * 2 * i;
		if (t == 0) continue;
		if ((p / t) < 0) continue;
		if (p % t) continue;
		else ans++;
	}
	printf("%lld", ans);
}
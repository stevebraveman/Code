#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define MOD 1000000007
#define MAXN 1000100
ll T, n, m, ans = 0, tot, d[MAXN + 10], num[MAXN + 10], p[MAXN + 10];
template <typename Tp>
Tp gcd(Tp a, Tp b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
bool chk[MAXN + 10];
void seive() {
	d[1] = 1;
	p[1] = 1;
	num[1] = 1;
	chk[1] = 1;
	for (ll i = 2; i <= MAXN; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			num[i] = 1;
			d[i] = 2;
		}
		for (int j = 1; j <= tot && i * p[j] <= MAXN; j++) {
			chk[i * p[j]] = 1;
			if (!(i % p[j])) {
				num[i * p[j]] = num[i] + 1;
				d[i * p[j]] = d[i] / (num[i] + 1) * (num[i * p[j]] + 1);
				break;
			}
			d[i * p[j]] = d[i] * d[p[j]];
			num[i * p[j]] = 1;
		}
	}
}
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
int main() {
	scanf("%lld", &T);
	while (T--) {
		ans = 0;
		scanf("%lld%lld", &n, &m);
		if (n > m) std::swap(n, m);
		for (ll l = 1, r; l <= n; l = r + 1) {
			r = min(n / (n / l), m / (m / l));
			ans += ((m / l) * (n / l) % MOD) * (r - l + 1 + MOD) % MOD;
		}
		printf("%d\n", ans % MOD);
	}
	return 0;
}
/*
int main() {
	scanf("%lld", &T);
	seive();
	while (T--) {
		ans = 0;
		scanf("%lld%lld", &n, &m);
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= m; j++) {
				ans += d[gcd(i, j)];
			}
		}
		printf("%lld\n", ans);
	}
}*/
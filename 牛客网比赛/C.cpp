#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define MAXN 10010100
ll n, m, cnt;
ll k[MAXN];
void swap(ll &n, ll &m) {
	ll t = n;
	n = m;
	m = t;
}
template <typename Tp>
Tp gcd(Tp a, Tp b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	scanf("%lld%lld", &n, &m);
	if (gcd(n, m) == 1) {
		puts("1");
		return 0;
	}
	if (n > m) {
		swap(n, m);
	}
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (m % i == 0) {
				k[++cnt] = i;
			}
			if (m % (n / i) == 0) {
				k[++cnt] = n / i;
			}
		}
	}
	cnt = (std::unique(k + 1, k + 1 + cnt) - k - 1);
	std::sort(k + 1, k + 1 + cnt);
	for (ll i = 1; i <= cnt; i++) {
		printf("%lld ", k[i]);
	}
	puts("");
	return 0;
}
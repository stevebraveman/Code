#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAXN 10000010
#define ll long long
ll chk[MAXN], p[MAXN], mu[MAXN], g[MAXN], sum[MAXN], tot;
template <typename _Tp>
_Tp min(_Tp a, _Tp b) {
	if (a < b) return a;
	else return b;
}
void shai() {
	for (int i = 2; i <= MAXN; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			mu[i] = -1;
			g[i] = 1;
		}
		for (int j = 1; j <= tot && i * p[j] <= MAXN; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				mu[i * p[j]] = -mu[i];
				g[i * p[j]] = mu[i] - g[i];
			}
			else {
				mu[i * p[j]] = 0;
				g[i * p[j]] = mu[i];
				break;
			}
		}
	}
	sum[0] = 0;
	for (int i = 1; i <= MAXN; i++) {
		sum[i] = sum[i - 1] + g[i];
	}
}
ll t;
ll n, m;
int main() {
	shai();
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld", &n, &m);
		if (n > m) std::swap(n, m);
		ll ans = 0;
		for (int i = 1, l; i <= n; i = l + 1) {
			l = min(n / (n / i), m / (m / i));
			ans += (n / i) * (m / i) * (sum[l] - sum[i - 1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
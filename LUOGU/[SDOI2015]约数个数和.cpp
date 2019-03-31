#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000100
#define ll long long
ll T, p[MAXN], mu[MAXN], tot, f[MAXN], k, n, m, res, d[MAXN], c[MAXN];
bool chk[MAXN];
ll min(ll a, ll b) {
	if (a < b) return a;
	else return b;
}
void shai() {
	chk[1] = 1;
	mu[1] = 1;
	d[1] = 1;
	c[1] = 1;
	for (ll i = 2; i <= MAXN; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			mu[i] = -1;
			c[i] = 1;
			d[i] = 2;
		}
		for (ll j = 1; j <= tot && i * p[j] <= MAXN; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				mu[i * p[j]] = -mu[i];
				d[i * p[j]] = d[i] * 2;
				c[i * p[j]] = 1;
			}
			else {
				d[i * p[j]] = d[i] / (c[i] + 1) * (c[i] + 2);
				c[i * p[j]] = c[i] + 1;
				mu[i * p[j]] = 0;
				break;
			}
		}
	}
	for (ll i = 1; i <= MAXN; i++) {
		mu[i] = mu[i - 1] + mu[i];
		d[i] += d[i - 1];
	}
}
template <typename Tp>
void swap(Tp &a, Tp &b) {
	Tp t = a;
	a = b;
	b = t;
}
int main() {
	// freopen("data.in", "r", stdin);
	shai();
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%lld", &n, &m);
		if (n > m) swap(n, m);
		res = 0;
		for (ll l = 1, r = 0; l <= n; l = r + 1) {
			r = min(n / (n / l), m / (m / l));
			res += (mu[r] - mu[l - 1]) * d[n / l] * d[m / l];
		}
		printf("%lld\n", res);
	}
}
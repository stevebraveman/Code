#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <tr1/unordered_map>
#define MAXN 10000010
#define ll long long
#define MOD 1000000007
using namespace std;
tr1::unordered_map<ll, ll> ans2;
bool p1;
ll k, n, p[MAXN], tot, f[MAXN], ans, phi[MAXN], pre2[MAXN];
bool chk[MAXN];
bool p2;

void seive(ll li) {
	chk[1] = f[1] = phi[1] = 1;
	for (ll i = 2; i <= li; i++) {
		if (!chk[i]) {
			phi[i] = i - 1;
			f[i] = i - 1;
			if (k % i == 0) f[i]++;
			p[++tot] = i;
		}
		for (int j = 1; j <= tot && i * p[j] <= li; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				phi[i * p[j]] = phi[i] * phi[p[j]];
				f[i * p[j]] = f[i] * f[p[j]];
			}
			else {
				phi[i * p[j]] = phi[i] * p[j];
				if (k % p[j]) f[i * p[j]] = f[i] * p[j];
				else f[i * p[j]] = f[i] * f[p[j]];
				break;
			}
		}
	}
	for (int i = 1; i <= li; i++) {
		pre2[i] = (pre2[i] + pre2[i - 1]) % MOD;
	}
}
template <typename T>
T gcd(T a, T b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
ll euler(ll x) {
	ll r = x;
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			r -= r / i;
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) r -= r / x;
	return r;
}
ll getphi(ll x) {
	if (x <= MAXN) return pre2[x];
	if (ans2[x]) return ans2[x];
	ll ans = x * (x + 1LL) / 2;
	for (ll l = 2, r; l <= x; l = r + 1) {
		r = x / (x / l);
		ans -= 1LL * (r - l + 1LL) * getphi(x / l);
	}
	return ans2[x] = ans;
}
int main() {
#ifndef ONLINE_JUDGE
	printf("%.2f\n", 1.0 * (&p2 - &p1) / (1024 * 1024));
#endif
	scanf("%lld%lld", &n, &k);
	seive(n);
	if (k == 1) {
		printf("%lld", getphi(n) % MOD);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		ans += f[i];
		ans %= MOD;
	}
	printf("%lld", euler(k) % MOD * ans % MOD);
}
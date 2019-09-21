#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tr1/unordered_map>
#define MAXN 5000010
#define ll long long
using namespace std;
tr1::unordered_map <ll, ll> ans1;
ll n, m, mod, tot, phi[MAXN], p[MAXN], sum[MAXN + 10], kp;
bool chk[MAXN];
void getphi() {
	chk[1] = 1;
	phi[1] = 1;
	for (ll i = 2; i <= MAXN; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			phi[i] = i - 1;
		}
		for (ll j = 1; j <= tot && i * p[j] <= MAXN; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				phi[i * p[j]] = phi[i] * phi[p[j]];
			}
			else {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
		}
	}
	for (ll i = 1; i <= MAXN; i++) {
		sum[i] = sum[i - 1] + (((i * i) % mod) * phi[i]) % mod;
		sum[i] %= mod;
	}
}
ll cube(ll x) {
	x %= mod;
	return ((x * (x + 1) / 2) % mod * (((x + 1) * x / 2) % mod)) % mod;
}
ll square(ll x) {
	x %= mod;
	return (((((x * (x + 1)) % mod) * (2 * x + 1)) % mod) * kp) % mod;
}
ll dyh(ll x) {
	if (x <= MAXN) return sum[x];
	if (ans1[x]) return ans1[x];
	ll ans = cube(x);
	for (ll l = 2, r; l <= x; l = r + 1) {
		r = x / (x / l);
		ans -= 1LL * (dyh(x / l) % mod) * ((square(r) - square(l - 1) + mod) % mod) % mod;
	}
	ans = (ans + mod) % mod;
	return ans1[x] = ans;
}
ll F(ll x) {
	ll ans = 0;
	for (ll l = 1, r; l <= x; l = r + 1) {
		r = x / (x / l);
		ans += 1LL * (1LL * cube(x / l) % mod) * ((dyh(r) - dyh(l - 1) + mod) % mod) % mod;
		ans %= mod;
	}
	return ans;
}
ll qpow(ll a, ll b, ll m) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res % m * (a % m)) % m;
		b >>= 1;
		a = (a % m * (a % m)) % m;
	}
	return res % m;
}
int main() {
	scanf("%lld%lld", &mod, &n);
	kp = qpow(6, mod - 2, mod);
	getphi();
	printf("%lld\n", F(n));
	return 0;
}
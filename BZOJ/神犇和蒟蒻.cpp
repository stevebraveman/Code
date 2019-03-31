#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tr1/unordered_map>
#define MAXN 5001000
#define MOD 1000000007
#define ll long long
#define re register
#define int long long
using namespace std;
tr1::unordered_map<ll, ll> ans2;
int p[MAXN], phi[MAXN], tot, t, n;
ll pre2[MAXN], kk, tt;
bool chk[MAXN];
ll qpow(ll a, ll b, ll m) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return res % m;
}
void getshai() {
	phi[1] = 1;
	chk[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= tot && i * p[j] <= MAXN; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				phi[i * p[j]] = phi[i] * phi[p[j]];
			}
			else {
				phi[i * p[j]] = p[j] * phi[i];
				break;
			}
		}
	}
	for (int i = 1; i <= MAXN; i++) {
		pre2[i] = pre2[i - 1] + (ll)(phi[i] * i) % MOD;
		pre2[i] %= MOD;
	}
}
ll sum(ll a) {
	return a * (a + 1) % MOD * (2 * a + 1) % MOD * kk % MOD;
}
ll getphi(ll x) {
	if (x <= MAXN) return pre2[x];
	if (ans2[x]) return ans2[x];
	ll ans = sum(x);
	for (re ll l = 2, r; l <= x; l = r + 1) {
		r = x / (x / l);
		ans -= 1LL * (r - l + 1LL) * (l + r) % MOD * tt % MOD * getphi(x / l);
		ans += MOD;
		ans %= MOD;
	}
	return ans2[x] = ans;
}
signed main() {
	getshai();
	scanf("%d", &n);
	kk = qpow(6, MOD - 2, MOD);
	tt = qpow(2, MOD - 2, MOD);
	puts("1");
	printf("%lld", getphi((ll)n));
}
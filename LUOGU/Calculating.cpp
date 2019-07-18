#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
#define MOD 998244353
ll n, m;
ll calc(ll a) {
	ll ans = 0;
	for (ll l = 1, r; l <= a; l = r + 1) {
		r = a / (a / l);
		ans += (a / l) * (r - l + 1) % MOD;
		ans %= MOD;
	}
	return ans;
}
int main() {
	scanf("%lld%lld", &n, &m);
	printf("%lld", ((calc(m) - calc(n - 1)) % MOD + MOD) % MOD);
	return 0;
}
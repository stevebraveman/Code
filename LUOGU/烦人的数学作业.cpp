#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define MOD 1000000007
ll ans1[30], ans2[30], t[30], f[30], tot;
ll dp(ll n, ll *p) {
	ll l = 0, tot;
	ll a[30] = {0};
	while (n) {
		a[++l] = n % 10;
		n /= 10;
	}
	for (ll i = l; i >= 1; i--) {
		for (ll j = 0; j <= 9; j++) {
			p[j] += f[i - 1] * a[i];
			p[j] %= MOD;
		}
		for (ll j = 0; j < a[i]; j++) {
			p[j] += t[i - 1];
			p[j] %= MOD;
		}
		tot = 0;
		for (int j = i - 1; j >= 1; j--) {
			tot = tot * 10 + a[j];
			tot %= MOD;
		}
		p[a[i]] += tot + 1;
		p[0] -= t[i - 1];
		p[a[i]] % MOD;
		p[0] += MOD;
		p[0] %= MOD;
	}
}
ll l, r, p, q;
int T;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &l, &r);
		// read(l), read(r);
		memset(ans1, 0, sizeof(ans1));
		memset(ans2, 0, sizeof(ans2));
		memset(f, 0, sizeof(f));
		memset(t, 0, sizeof(t));
		p = l, q = r;
		t[0] = 1;
		for (ll i = 1; i <= 20; i++) {
			f[i] = f[i - 1] * 10 + t[i - 1];
			t[i] = 10 * t[i - 1];
		}
		dp(l - 1, ans1);
		dp(r, ans2);
		tot = 0;
		for (int i = 0; i <= 9; i++) {
			tot += (ans2[i] - ans1[i] + MOD) % MOD * i % MOD;
			tot %= MOD;
		}
		printf("%lld\n", tot);
	}
}
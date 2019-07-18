#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MOD 1000000007
#define ll long long
#define sqr(x) ((((x) % MOD) * ((x) % MOD)) % MOD)
ll p, n, k, inv48;
ll qpow(ll a, ll b, ll m) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return res % m;
}
int main() {
	// freopen("biao.out", "w", stdout);
	scanf("%lld", &n);
	ll p = n % 12;
	inv48 = qpow(48, MOD - 2, MOD);
	if (p == 0) k = n % MOD * (n % MOD) % MOD * inv48 % MOD;
	if (p == 1) k = (sqr(n) + 6 * n % MOD - 7 + MOD) % MOD * inv48 % MOD;
	if (p == 2) k = (sqr(n) - 4 + MOD) % MOD * inv48 % MOD;
	if (p == 3) k = (sqr(n) + 6 * n % MOD + 12 + MOD) % MOD * inv48 % MOD;
	if (p == 4) k = (sqr(n) - 16 + MOD) % MOD * inv48 % MOD;
	if (p == 5) k = (sqr(n) + 6 * n % MOD - 7 + MOD) % MOD * inv48 % MOD;
	if (p == 6) k = (sqr(n) + 12 + MOD) % MOD * inv48 % MOD;
	if (p == 7) k = (sqr(n) + 6 * n % MOD + 5 + MOD) % MOD * inv48 % MOD;
	if (p == 8) k = (sqr(n) - 16 + MOD) % MOD * inv48 % MOD;
	if (p == 9) k = (sqr(n) + 6 * n % MOD + 9 + MOD) % MOD * inv48 % MOD;
	if (p == 10) k = (sqr(n) - 4 + MOD) % MOD * inv48 % MOD;
	if (p == 11) k = (sqr(n) + 6 * n % MOD + 5 + MOD) % MOD * inv48 % MOD;
	/*
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		gg.clear();
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k <= i; k++) {
				if (j + k >= i) {
					continue;
				}
				int p = i - j - k;
				la[1] = p;
				la[2] = j;
				la[3] = k;
				std::sort(la + 1, la + 1 + 3);
				hash = n * n * la[1] + n * la[2] + la[3];
				if (gg[hash] == 1) continue;
				gg[hash] = 1;
				if (k + j > p && j + p > k && k + p > j) ans++;
			}
		}
		if (i % 4 == 1) puts("=======");
		printf("%d %d %d %d %d %d\n", i, i % 4, i / 4, (i - i / 2) / 2, ans);
	}
	*/
	printf("%lld", k);
}
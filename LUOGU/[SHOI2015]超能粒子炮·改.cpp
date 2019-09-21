#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
#define MAXN 1001010
#define MOD 2333
ll C[3010][3010], f[3010][3010];
ll Lucas(ll n, ll m, ll p) {
	if (!m) return 1;
	if (n == m) return 1;
	if (n < m) return 0;
	else return C[n % p][m % p] * Lucas(n / p, m / p, p) % p;
}
ll fun(ll n, ll m) {
	if (m < 0) return 0;
	if (n == 0) return 1;
	if (m == 0) return 1;
	if (n < MOD && m < MOD) return f[n][m];
	return (fun(n / MOD, m / MOD - 1) * f[n % MOD][MOD - 1] % MOD + Lucas(n / MOD, m / MOD, MOD) * f[n % MOD][m % MOD] % MOD) % MOD;
}
ll n, m, T;
int main() {
	scanf("%lld", &T);
	C[1][1] = 1;
	for (int i = 0; i <= 3000; i++) {
		C[i][0] = 1;
	}
	for (int i = 2; i <= 3000; i++) {
		for (int j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
	f[0][0] = 0;
	for (int i = 0; i <= 3000; i++) {
		f[i][0] = 1;
	}
	for (int i = 0; i <= 3000; i++) {
		for (int j = 1; j <= 3000; j++) {
			f[i][j] = (f[i][j - 1] + C[i][j]) % MOD;
		}
	}
	while (T--) {
		scanf("%lld%lld", &n, &m);
		// printf("%lld ", T);
		printf("%lld\n", fun(n, m));
	}
}
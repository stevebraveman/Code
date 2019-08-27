#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 1 << 18
#define MOD 1000000007
namespace Mker {
	#include<climits>
	#define ull unsigned long long
	#define uint unsigned int
	ull sd;int op;
	inline void init() {
		scanf("%llu %d", &sd, &op);
	}
	inline ull ull_rand() {
		sd ^= sd << 43;
		sd ^= sd >> 29;
		sd ^= sd << 34;
		return sd;
	}
	inline ull rand() {
		if (op == 0) return ull_rand() % USHRT_MAX + 1;
		if (op == 1) return ull_rand() % UINT_MAX + 1; 
		if (op == 2) return ull_rand();
	}
}
long long qpow(long long a, long long b, long long m) {
	long long res = 1;
	while (b) {
		if (b) res = (1LL * res * a) % m;
		b >>= 1;
		a = (1LL * a * a) % m;
	}
	return res % m;
}
int T;
long long a[MAXN], ans;
int main() {
	scanf("%d", &T);
	Mker::init();
	if (Mker::sd == 0) {
		printf("0");
		return 0;
	}
	a[0] = -3;
	a[1] = -6;
	a[2] = -12;
	for (int i = 3; i <= MAXN; i++) {
		a[i] = (3 * a[i - 1] % MOD + a[i - 2] % MOD - 3 * a[i - 3] % MOD + qpow(3, i, MOD) % MOD + MOD) % MOD;
	}
	while (T--) {
		long long p = Mker::rand();
		// printf("%lld", a[p]);
		a[p] = (a[p] % MOD + MOD) % MOD;
		ans ^= a[p];
	}
	printf("%lld", ans);
}
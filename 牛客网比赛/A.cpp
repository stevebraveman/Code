#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
#define MAXN 1000010
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (1LL * a * res) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return res % MOD;
}
int n, a[MAXN], tot;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	// freopen("C:\\Users\\Administrator\\Downloads\\8030387_1573202678826_jihetongji\\A_sample.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	std::sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		// printf("%d ", a[i]);
		tot = (tot + 1LL * a[i] * qpow(2, n - i) % MOD) % MOD;
		// tot %= MOD;
	}
	// puts("");
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		// printf("%d ", a[i]);
		tot = (tot - 1LL * a[i] * qpow(2, n - i) % MOD + MOD) % MOD;
		// tot %= MOD;
	}
	printf("%d\n", tot);
}
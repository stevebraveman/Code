#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define MOD 1000000007
#define int long long
struct Mat {
	ll a[20][20];
	void clear() {
		memset(a, 0, sizeof(a));
	}
	void init() {
		for (int i = 0; i < 20; i++) {
			a[i][i] = 1;
		}
	}
};
ll n, m;
Mat operator * (Mat a, Mat b) {
	Mat c;
	c.clear();
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= m; k++) {
				c.a[i][j] = (c.a[i][j] + (a.a[i][k] * b.a[k][j]) % MOD) % MOD;
			}
		}
	}
	return c;
}
Mat qpow(Mat a, ll b) {
	Mat res;
	res.clear();
	res.init();
	while (b) {
		if (b & 1) res = res * a;
		b >>= 1;
		a = a * a;
	}
	return res;
}
Mat a, q, f;
ll fb[20];
signed main() {
	scanf("%lld%lld", &n, &m);
	a.clear();
	q.clear();
	f.clear();
	// std::cout << n << std::endl;
	for (int i = 1; i <= m + 1; i++) {
		fb[i] = 1LL * i + 1;
	}
	for (int i = 0; i <= m; i++) {
		f.a[0][i] = fb[i + 1];
	}
	if (n < m + 1) {
		printf("%lld", fb[n]);
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		a.a[i][i - 1] = 1;
	}
	a.a[0][m] = 1;
	a.a[m][m] = 1;
	q = f * qpow(a, n - 1);
	std::cout << q.a[0][0] << std::endl;
	return 0;
}
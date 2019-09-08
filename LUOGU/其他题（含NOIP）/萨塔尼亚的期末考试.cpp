#include <iostream>
#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
#define MOD 998244353
struct Mat{
	ll a[2][2];
	void clear() {
		memset(a, 0, sizeof(a));
	}
	void init() {
		memset(a, 0, sizeof(a));
		for (int i = 0; i <= 1; i++) {
			a[i][i] = 1;
		}
	}
};
Mat operator * (Mat a, Mat b) {
	Mat c;
	c.clear();
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				c.a[i][j] = (c.a[i][j] + (a.a[i][k] * b.a[k][j]) % MOD) % MOD;
			}
		}
	}
	return c;
}
Mat qpow(Mat a, ll n) {
	Mat b;
	b.init();
	while (n) {
		if (n & 1) b = b * a;
		n >>= 1;
		a = a * a;
	}
	return b;
}
ll qpow2(ll a, ll b) {
	ll res = 1;
	a %= MOD;
	while (b) {
		if (b & 1) res = ((res % MOD) * (a % MOD)) % MOD;
		b >>= 1;
		a = ((a % MOD) * (a % MOD)) % MOD;
	}
	return res % MOD;
}
int main() {
	ll n, t;
	scanf("%lld", &t);
	while (t--) {
		Mat f, a, q, p, r;
		f.clear();
		a.clear();
		q.clear();
		f.a[0][0] = f.a[0][1] = 1;
		a.a[0][0] = 0;
		a.a[1][0] = a.a[0][1] = a.a[1][1] = 1;
		scanf("%lld" , &n);
		q = f * qpow(a, n + 1);
		p = f * qpow(a, n + 2);
		ll e = (q.a[0][0] % MOD) * n % MOD, l = p.a[0][0] % MOD;
		e -= l;
		e += MOD;
		e += 2;
		e %= MOD;
		printf("%lld\n", ((e % MOD) * (qpow2((n * (n + 1) / 2) % MOD, MOD - 2) % MOD)) % MOD);
	}
	
}
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
		a[0][0] = a[1][1] = 1;
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
int T;
ll n;
int main() {
	scanf("%d", &T);
	Mat f, a, q, p;
	f.clear();
	a.clear();
	q.clear();
	p.clear();
	f.a[0][0] = f.a[0][1] = 1;
	a.a[1][0] = a.a[0][1] = a.a[0][0] = 1;
	a.a[1][1] = 0;
	while (T--) {
		scanf("%lld", &n);
		n--;
		q = qpow(a, n);
		printf("%lld\n", (q.a[0][0] + (q.a[0][1] << 1) % MOD + (n + 1) % 2) % MOD);
	}
}
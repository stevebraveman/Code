#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
#define ll long long
inline ll mt(ll x, ll y, ll mod) {
	ll tmp=(x * y - (ll)((long double)x / mod * y + 1.0e-8) * mod);
	return tmp < 0 ? tmp + mod : tmp;
}
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
ll n, m, p;
Mat operator * (Mat a, Mat b) {
	Mat c;
	c.clear();
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= m; k++) {
				c.a[i][j] = (c.a[i][j] + mt(a.a[i][k], b.a[k][j], p)) % p;
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
ll qpown(ll a, ll b) {
	ll res = 1LL;
	while (b) {
		if (b & 1) res = mt(res, a, p);
		b >>= 1;
		a = mt(a, a, p);
	}
	return res % p;
}
Mat a, q, f;
ll fb[20], g;
signed main() {
	scanf("%lld%lld", &n, &p);
	a.clear();
	q.clear();
	f.clear();
	n++;
	m = 1;
	// std::cout << n << std::endl;
	for (int i = 1; i <= m + 1; i++) {
		fb[i] = 1LL * i + 1;
	}
	for (int i = 0; i <= m; i++) {
		f.a[0][i] = fb[i + 1];
	}
	for (int i = 1; i <= m; i++) {
		a.a[i][i - 1] = 1;
	}
	a.a[0][m] = 1;
	a.a[m][m] = 1;
	q = f * qpow(a, n - 1);
	g = q.a[0][0] - n - 1;
	std::cout << qpown((g + p) % p, n) << std::endl;
	return 0;
}
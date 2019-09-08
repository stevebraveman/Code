// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ull unsigned long long
#define MOD 1000000007
namespace Mker {
	unsigned long long SA, SB, SC;
	void init() {
		scanf("%llu%llu%llu", &SA, &SB, &SC);
	}
	inline unsigned long long rand() {
		SA ^= SA << 32, SA ^= SA >> 13, SA ^= SA << 1;
		unsigned long long t = SA;
		SA = SB, SB = SC, SC ^= t ^ SA; return SC;
	}
}
struct Mat{
	int a[2][2];
	inline void clear() {
		memset(a, 0, sizeof(a));
	}
	inline void init() {
		a[0][0] = a[1][0] = a[1][1] =a[0][1] = 0;
		a[0][0] = a[1][1] = 1;
	}
};
inline Mat operator * (Mat a, Mat b) {
	Mat c;
	c.a[0][0] = c.a[1][0] = c.a[0][1] = c.a[1][1] = 0;
	c.a[0][0] = (c.a[0][0] + 1LL * a.a[0][0] * b.a[0][0] + 1LL * a.a[0][1] * b.a[1][0]) % MOD;
	c.a[0][1] = (c.a[0][1] + 1LL * a.a[0][0] * b.a[0][1] + 1LL * a.a[0][1] * b.a[1][1]) % MOD;
	c.a[1][0] = (c.a[1][0] + 1LL * a.a[1][0] * b.a[0][0] + 1LL * a.a[1][1] * b.a[1][0]) % MOD;
	c.a[1][1] = (c.a[1][1] + 1LL * a.a[1][0] * b.a[0][1] + 1LL * a.a[1][1] * b.a[1][1]) % MOD;
	return c;
}
inline Mat qpow(Mat a, ull n) {
	Mat b;
	b.init();
	while (n) {
		if (n & 1) b = b * a;
		n >>= 1;
		a = a * a;
	}
	return b;
}
ull sq;
Mat x1[50000], x2[50000], g;
int main() {
	int t;
	scanf("%d", &t);
	Mker::init();
	int ans = 0;
	Mat f, a, q;
	a.clear(), q.clear();
	a.a[0][0] = 233, a.a[1][0] = 666;
	a.a[0][1] = 1;
	x1[0].init(), x2[0].init();
	sq = sqrt(MOD - 1) + 1;
	a.a[1][1] = 0;
	g = qpow(a, sq);
	for (int i = 1; i <= sq + 1; i++) {
		x1[i] = x1[i - 1] * a;
		x2[i] = x2[i - 1] * g;
	}
	while (t--) {
		int k = (Mker::rand() - 1) % 1000000006;
		if (k <= 1) ans ^= k;
		q = x1[k % sq] * x2[k / sq];
		ans ^= q.a[0][0];
	}
	std::cout << ans;
}
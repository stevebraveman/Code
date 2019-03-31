#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#define ull unsigned long long
#define MOD 1000000007
namespace Mker {
	unsigned long long SA, SB, SC;
	void init() {
		scanf("%llu%llu%llu", &SA, &SB, &SC);
	}
	unsigned long long rand() {
		SA ^= SA << 32, SA ^= SA >> 13, SA ^= SA << 1;
		unsigned long long t = SA;
		SA = SB, SB = SC, SC ^= t ^ SA; return SC;
	}
}
struct Mat{
	ull a[2][2];
	void clear() {
		memset(a , 0 , sizeof(a));
	}
	void init() {
		memset(a , 0 , sizeof(a));
		for (int i = 0 ; i <= 1 ; i++) {
			a[i][i] = 1;
		}
	}
};
Mat operator * (Mat a , Mat b) {
	Mat c;
	c.clear();
	for (int i = 0 ; i < 2 ; i++) {
		for (int j = 0 ; j < 2 ; j++) {
			for (int k = 0 ; k < 2 ; k++) {
				c.a[i][j] = (c.a[i][j] + (a.a[i][k] * b.a[k][j]) % MOD) % MOD;
			}
		}
	}
	return c;
}
Mat qpow(Mat a , ull n) {
	Mat b;
	b.init();
	while (n) {
		if (n & 1) b = b * a;
		n >>= 1;
		a = a * a;
	}
	return b;
}
int cnt;
int main() {
	freopen("data.out", "w", stdout);
	int t;
	scanf("%d", &t);
	Mker::init();
	ull ans = 0;
	Mat f , a , q;
	f.clear();
	a.clear();
	q.clear();
	f.a[0][0] = 233;
	f.a[0][1] = 1;
	a.a[0][0] = 233;
	a.a[1][0] = 666;
	a.a[0][1] = 1;
	a.a[1][1] = 0;
	clock_t t1 = clock();
	ull k, x = 0;
	while (t--) {
		k = Mker::rand() % 1000000006LL - 1;
		if (k == -1) continue;
		printf("%llu %llu %llu %llu\n", Mker::SA, Mker::SB, Mker::SC, Mker::SA ^ Mker::SB ^ Mker::SC);
	}
	std::cout << k << std::endl;
	q = f * qpow(a , k);
	ans ^= q.a[0][1];
	clock_t t2 = clock();
	std::cout << ans;
	#ifndef ONLINE_JUDGE
		puts("");
		printf("%.2fms", (double)(t2 - t1) * 1000 / CLOCKS_PER_SEC);
	#endif
}
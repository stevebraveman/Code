#include <iostream>
#include <cstring>
#include <cstdio>
#define ll long long
#define MOD 1000000007
using namespace std;
struct Mat {
	ll a[2][2];
	void init() {
		for (int i = 0 ; i <= 1 ; i++) {
			a[i][i] = 1;
		}
	}
	void clear() {
		memset(a , 0 , sizeof (a));
	}
};
Mat operator * (Mat a , Mat b) {
	Mat c;
	for (int i = 0 ; i < 2 ; i++) {
		for (int j = 0 ; j < 2 ; j++) {
			for (int k = 0 ; k < 2 ; k++) {
				c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % MOD ) % MOD;
			}
		}
	}
}
Mat qpow(Mat a , ll x) {
	Mat c;
	c.clear();
	c.init();
	while (x) {
		if (x & 1) c = c * a;
		x >>= 1;
		a = a * a;
	}
	return c;
}
int main() {
	ll n;
	scanf("%lld" , & n);
	Mat a,b;
	if (n == 1) {
		printf ("1");
		return 0;
	}
	a.a[0][0] = a.a[0][1] = b.a[1][0] = b.a[0][1] = b.a[1][1] = 1;
	Mat ans = a * qpow(b , n - 1);
	printf("%lld" , ans.a[0][0] % MOD);
}
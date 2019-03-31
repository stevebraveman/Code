#include <iostream>
#include <cstring>
#include <cstdio>
#define ll long long
#define MOD 1000000007
using namespace std;
ll n , y;
struct Mat {
	ll a[102][102];
	void init() {
		for (int i = 0 ; i < n ; i++) {
			a[i][i] = 1;
		}
	}
	void clear() {
		memset(a , 0 , sizeof (a));
	}
};
Mat operator * (Mat a , Mat b) {
	Mat c;
	c.clear();
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			for (int k = 0 ; k < n ; k++) {
				c.a[i][j] = (c.a[i][j] + (a.a[i][k] * b.a[k][j]) % MOD ) % MOD;
			}
		}
	}
	return c;
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
Mat a;
int main() {
	scanf("%lld%lld" , &n , &y);
	for (ll i = 0 ; i < n ; i++) {
		for (ll j = 0 ; j < n ; j++) {
			scanf("%lld" , &a.a[i][j]);
		}
	}
	Mat ans = qpow(a , y);
	for (ll i = 0 ; i < n ; i++) {
		for (ll j = 0 ; j < n ; j++) {
			printf("%lld " , ans.a[i][j]);
		}
		puts("");
	}
}
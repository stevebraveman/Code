#include <iostream>
#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
#define MOD 1000000007
struct Mat{
	ll a[2][2];
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
Mat qpow(Mat a , ll n) {
	Mat b;
	b.init();
	while (n) {
		if (n & 1) b = b * a;
		n >>= 1;
		a = a * a;
	}
	return b;
}
ll gcd(int a , int b) {
	if (b == 0)	return a;
	else return gcd(b , a % b);
}
int main() {
	ll n , m , g;
	scanf("%lld%lld" , &n , &m);
	g = gcd(n , m);
	if (g <= 2){
		printf("1");
		return 0;
	}
	Mat f , a , q;
	f.clear();
	a.clear();
	q.clear();
	f.a[0][0] = f.a[0][1] = 1;
	a.a[0][0] = 0;
	a.a[1][0] = a.a[0][1] = a.a[1][1] = 1;
	q = f * qpow(a , g - 1);
	std::cout << q.a[0][0];
}
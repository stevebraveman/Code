#include <iostream>
#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
ll n , m , p , q , a_1 , a_2;
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
ll mula(ll x , ll y) {
	x += y;
	if (x >= m) x -= m;
	return x;
}
ll mult(ll x , ll y) {
	ll p = 0;
	while (y) {
		if (y & 1) p = (p + x) % m;
		x = (x + x) % m;
		y >>= 1;
	}
	return p;
}
Mat operator * (Mat a , Mat b) {
	Mat c;
	c.clear();
	for (int i = 0 ; i < 2 ; i++) {
		for (int j = 0 ; j < 2 ; j++) {
			for (int k = 0 ; k < 2 ; k++) {
				c.a[i][j] = mula(c.a[i][j] %m , mult(a.a[i][k] , b.a[k][j]) % m) % m;
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
int main() {
	scanf("%lld%lld%lld%lld%lld%lld" , &q , &p , &a_1 , &a_2 , &n , &m);
	Mat f , a , w;
	f.clear();
	a.clear();
	w.clear();
	f.a[0][0] = a_1;
	f.a[0][1] = a_2;
	a.a[0][0] = 0;
	a.a[1][0] = 1;
	a.a[0][1] = p;
	a.a[1][1] = q;
	w = f * qpow(a , n - 2);
	std::cout << w.a[0][1] % m;
}
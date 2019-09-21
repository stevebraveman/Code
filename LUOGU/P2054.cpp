#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define ll long long
ll n , m , l , r , g , h;
inline ll qpow(ll k , ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = (res * k) % (n + 1);
		p >>= 1;
		k = (k * k) % (n + 1);
	}
	return res;
}
void exgcd(ll a , ll b , ll &x , ll &y) {
	if (!b) {
		x = 1;
		y = 0;
		return;
	}
	exgcd(b , a % b , x , y);
	x ^= y ^= x ^= y;
	y -= (a / b) * x;
}
int main() {
	scanf("%lld%lld%lld" , &n , &m , &l);
	r = qpow(2 , m);
	exgcd (r , n + 1 , g , h);
	while (g < 0) g += n + 1;
	printf("%lld" , g * l % (n + 1));
	return 0;
}
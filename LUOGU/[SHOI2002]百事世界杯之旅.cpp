#include <iostream>
#include <cstdio>
#define ll long long 
ll gcd(ll a , ll b) {
	if (b == 0) return a;
	else return gcd(b , a % b);
}
ll lcm(ll a , ll b) {
	return a * b / gcd(a , b);
}
ll n , ans , ws1 = 0 , ws2 = 0 , fm = 1 , fz = 0 , yfz = 1 , d = 0 , k , r;
int main() {
	scanf("%lld" , &n);
	for (ll i = 1 ; i <= n ; i++) {
		fz = fz * i + fm * n;
		fm *= i;
		r = gcd(fm , fz);
		fm /= r;
		fz /= r;
	}
	r = fz / fm;
	if (fm == 1) {
		printf("%lld" , fz);
	}
	else {
		ll y = r;
		while (y != 0) {
			y /= 10;
			ws1++;
		}
		ll fmn = fm;
		while (fmn != 0) {
			fmn /= 10;
			ws2++;
		}
		for (ll i = 1 ; i <= ws1 ; i++) {
			printf(" ");
		}
		printf("%lld" , fz % fm);
		puts("");
		printf("%lld" , r);
		for (ll i = 1 ; i <= ws2 ; i++) {
			printf("-");
		}
		puts("");
		for (ll i = 1 ; i <= ws1 ; i++) {
			printf(" ");
		}
		printf("%lld" , fm);
	}
	return 0;
}
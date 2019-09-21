#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
ll phi(ll n) {
	ll ans = n;
	for (ll i = 2 ; i <= sqrt(n) ; i++) {
		if (n % i == 0) {
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}
ll n , a , tot = 0 , i;
int main() {
	scanf("%lld" , &n);
	for (i = 1 ; i * i < n ; i++) {
		if (n % i == 0) tot += i * phi(n / i) + (n / i) * phi(i);
	}
	if (i * i == n) tot += i * phi(i);
	printf("%lld" , tot);
}

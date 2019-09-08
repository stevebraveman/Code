#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define MAXN 50000
ll n , k , p , tot = 0 , ans = 1;
bool gauss(ll a) {
	if (a % 4 != 3) return 1;
	return 0;
}
int main() {
	scanf("%lld" , &n);
	while (!(n & 1)) n >>= 1;
	for (ll i = 2; i <= sqrt(n) ; i++) {
		p = 0;
		while (n % i == 0) {
			if (gauss(i)) p += 2;
			n /= i;
		}
		ans *= (p + 1);
	}
	if (n != 1) {
		if (gauss(n)) {
			ans *= 3;
		}
	}
	printf("%d" , ans * 4);
	return 0;
}

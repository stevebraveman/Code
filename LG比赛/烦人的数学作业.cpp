#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define MOD 1000000007
ll t , l , r , p , q;
int main() {
	freopen("data.in" , "r" , stdin);
	scanf("%lld" , &t);
	while (t--) {
		scanf("%lld%lld" , &l , &r);
		p = r - l + 1;
		q = l + r;
		if (p & 1) {
			q /= 2;
		}
		else {
			p /= 2;
		}
		printf("%d\n" , ((p % MOD) * (q % MOD)) % MOD);
	}
}
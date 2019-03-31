#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
ll t , l , r , p , q;
int main() {
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
		printf("%d\n" , ((p % 9) * (q % 9)) % 9);
	}
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define ll long long
ll n , m , t;
int main() {
	scanf("%lld" , &t);
	while (t--) {
		scanf("%lld%lld" , &n , &m);
		if ((n - ((n / m) + (n % m == 0 ? 1 : 0))) & 1) printf("1\n");
		else printf("0\n");
	}
}
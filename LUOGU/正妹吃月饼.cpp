#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
ll n , m , ans , i = 1 , j;
int main() {
	scanf("%lld%lld" , &n , &m);
	while ((n | (n + 1)) <= m) {
		n |= n + 1;
	}
	while (n) {
		ans++;
		n &= (n - 1);
	}
	printf("%lld" , ans);
}

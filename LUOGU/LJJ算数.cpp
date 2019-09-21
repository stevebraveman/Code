#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define MOD 1000000007
ll qpow(ll a , ll b , ll m) {
	ll res = 1;
	while (b) {
		if (b & 1) res = ((a % m) * (res % m)) % m;
		b >>= 1;
		a = ((a % m) * (a % m)) % m;
	}
	return res;
}
ll n , m;
int main() {
	scanf("%lld%lld" , &n , &m);
	printf("%lld" , (qpow(n , (qpow(n , m - 1 , MOD - 1) + MOD) % MOD , MOD) + MOD) % MOD);
}
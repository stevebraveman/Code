#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 123456789
#define ll long long
ll qpow(ll a , ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = ((res % MOD) * (a % MOD)) % MOD;
		b >>= 1;
		a = ((a % MOD) * (a % MOD)) % MOD;
	}
	return res % MOD;
}
ll n;
int main() {
	// freopen("data.in" , "r" , stdin);
	scanf("%lld" , &n);
	printf("%lld" , qpow(2 , n - 1));
}
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
#define MAXN 20010100
#define MOD 19491001
ll jc[MAXN];
void ft(ll n, ll p) {
	jc[0] = jc[1] = 1;
	for (ll i = 2; i <= n; i++) {
		jc[i] = jc[i - 1] * i % p;
	}
}
ll qpow(ll a, ll b, ll m) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return res % m;
}
ll C(ll n, ll m, ll p) {
	if (n < m) {
		return 0;
	}
	return jc[n] * qpow(jc[m], p - 2, p) % p * qpow(jc[n - m], p - 2, p) % p;
}
ll Lucas(ll n, ll m, ll p) {
	if (!n) return 1;
	else return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}
ll n, m, p, t;
int main() {
	ft(MOD, MOD);
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld", &n, &m);
		printf("%lld\n", Lucas(n + m, n, MOD));
	}
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define ll long long
#define MAXN 2000010
#define MOD 1000000009
ll n, m, jc[MAXN];
void ft(ll n) {
    jc[0] = jc[1] = 1;
    for (ll i = 2; i <= n; i++) {
        jc[i] = jc[i - 1] * i % MOD;
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
    if (n < m) return 0;
    if (!n) return 1;
    else return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}
int main() {
	scanf("%lld%lld", &n, &m);
	
	for (int i = 1; i <= n; i++) {

	}
}
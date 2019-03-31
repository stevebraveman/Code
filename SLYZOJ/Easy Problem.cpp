#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
ll t, m, mod;
ll multi(ll x, ll y, ll mod) {
    ll tmp = (x * y - (ll)((long double)x / mod * y + 1.0e-8) * mod);
    return tmp < 0 ? tmp + mod : tmp;
}
ll qpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = multi(res, a, mod) % mod;
        b >>= 1;
        a = multi(a, a, mod) % mod;
    }
    return res % mod;
}
int main() {
    scanf("%lld%lld", &t, &mod);
    while (t--) {
        scanf("%lld", &m);
        ll ans = qpow(4, m - 1, mod);
        printf("%lld\n", ans % mod);
    }
}
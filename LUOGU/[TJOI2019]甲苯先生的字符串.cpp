#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define ll long long
#define MOD 1000000007
ll n, len;
char s[MAXN];
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return res % MOD;
}
int main() {
    scanf("%lld", &n);
    scanf("%s", s);
    len = strlen(s);
    if (n < len) {
        
    }
}
#pragma GCC optimize(3)
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define ll long long
#define MOD 1000000007
template <typename Tp>
Tp gcd(Tp a, Tp b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
template <typename Tp>
Tp max(Tp a, Tp b) {
	if (a > b) return a;
	else return b;
}
inline ll mul(const ll a, const ll b, const ll md) {
    ll c = (ll)a * b - (ll)((ll)((long double)a * b / md) * md);
    return c < 0 ? md + c : ((ll)c > md ? c - md : c);
}
ll qpow(ll a, ll b, ll m) {
	ll ans = 1;
	a %= m;
	while(b) {
		if(b & 1) ans = mul(a, ans, m);
		b >>= 1;
		a = mul(a, a, m);
	}
	ans %= m;
	return ans;
}
ll ans = 0;
bool Rabin(ll p, ll x) {
    if(qpow(p, x - 1, x) != 1)
        return false;
    ll k = x - 1;
    while(!(k & 1))
    {
        k >>= 1;
        ll t = qpow(p, k, x);
        if(t != 1 && t != x - 1)
            return false;
        if(t == x - 1)
            return true;
    }
    return true;
}
bool Miller_Rabin(ll x) {
    if(x == 2 || x == 3 || x == 5 || x == 7 || x == 43)
        return true;
    if(x < 2)
        return false;
    return (Rabin(2, x) && Rabin(3, x) && Rabin(5, x) && Rabin(7, x) && Rabin(43, x));
}
ll mns(ll a, ll b) {
	if (a >= b) return a - b;
	else return b - a;
}
ll pollard_rho(ll n, ll c, ll stp){
	if (n % 2 == 0) return 2;
	if (n % 3 == 0) return 3;
	ll x = 2;
	ll y = x;
	ll d = 1;
	while (1) {
		ll _x = x, _y = y;
		for (ll i = 1; i <= stp; i++) {
			x = mul(x, x, n) + c;
			if (x >= n) x -= n;
			y = mul(y, y, n) + c;
			if (y >= n) y -= n;
			y = mul(y, y, n) + c;
			if (y >= n) y -= n;
			d = mul(d, mns(x, y), n);
		}
		d = gcd(d, n);
		if (d == 1) continue;
		if (d != n) return d;
		x = _x;
		y = _y;
		for (ll i = 1; i <= stp; i++) {
			x = mul(x, x, n) + c;
			if (x >= n) x -= n;
			y = mul(y, y, n) + c;
			if (y >= n) y -= n;
			y = mul(y, y, n) + c;
			if (y >= n) y -= n;
			d = gcd(n, mns(x, y));
			if (d != 1) return d % n;
		}
		return 0;
	}
}
ll find(ll n) {
	if(Miller_Rabin(n)) {
		return n;
	}
	ll d = 0;
	ll k = 1;
	ll s = pow(n, 0.1);
	while(d == 0) {
		d = pollard_rho(n, k++, s);
	}
	return max(find(d), find(n / d));
}
ll n;
int main() {
	srand(time(NULL));
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%lld", &n);
		ans = find(n);
		if (ans == n) {
			puts("Prime");
			continue;
		}
		printf("%lld\n", ans);
	}
}
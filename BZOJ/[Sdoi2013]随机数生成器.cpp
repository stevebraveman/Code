#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define ll long long
ll ex_gcd(ll a, ll b, ll &x, ll &y){
	if (b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll d = ex_gcd(b, a % b, x, y);
	ll temp = x; x = y; y = temp - a / b * y;
	return d;
}
bool liEu(ll a, ll b, ll c, ll &x, ll &y){
	ll d = ex_gcd(a, b, x, y);
	if (c % d != 0) return false;
	ll k = c / d;
	x *= k;
	y *= k;
	return true;
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
ll bsgs(ll a, ll b, ll p) {
	std::map <ll, ll> h;
	h.clear();
	b %= p;
	ll t = sqrt(p) + 1;
	for (int i = 0; i < t; i++) {
		ll v = b * qpow(a, i, p) % p;
		h[v] = i;
	}
	a = qpow(a, t, p);
	if (a == 0) return (b == 0) ? 1 : -1;
	for (int i = 0; i <= t; i++) {
		int v = qpow(a, i, p);
		int j = h.find(v) == h.end() ? -1 : h[v];
		if (j >= 0 && i * t - j >= 0) return i * t - j;
	}
	return -1;
}
ll n, a, b, k, m, x, flag, p, T, t, gg, _x, _y;
int main() {
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%lld%lld%lld%lld", &p, &a, &b, &x, &t);
		if (x == t) {
			puts("1");
			continue;
		}
		if (a == 0) {
			printf("%lld\n", ((b == t) ? (2LL) : (-1LL)));
			continue;
		}
		if (a == 1 && b == 0) {
			puts("-1");
			continue;
		}
		if (a == 1) {
			gg = t - x;
			_x = _y = 0;
			if (liEu(b, p, gg, _x, _y)) {
				printf("%lld\n", (_x % p + p) % p + 1);
			}
			else puts("-1");
			continue;
		}
		gg = ((t + b * qpow(a - 1, p - 2, p) % p) * qpow(x + b * qpow(a - 1, p - 2, p) % p, p - 2, p) % p + p) % p;
		gg = bsgs(a, gg, p);
		printf("%lld\n" , gg == -1 ? -1 : gg + 1);
	}
}
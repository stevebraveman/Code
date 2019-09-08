#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#define ll __int128
ll qpow(ll a , ll b , ll m) {
	ll res = 1;
	while (b) {
		if (b & 1) res = ((res  % m) * (a % m)) % m;
		b >>= 1;
		a = ((a % m) * (a % m)) % m;
	}
	return res % m;
}
ll bsgs(ll a , ll b , ll p) {
	ll t = sqrt(p) + 1;
	std::map <ll , ll> h;
	h.clear();
	for (ll i = 1 ; i <= t ; i++) {
		ll v = b * qpow(a , i , p) % p;
		h[v] = i;
	}
	a = qpow(a , t , p);
	if (a == 0) return b == 0 ? 1 : -1;
	for (ll i = 1 ; i <= t ; i++) {
		ll v = qpow(a , i , p);
		ll j = h.find(v) == h.end() ? -1 : h[v];
		if (j >= 0 && i * t - j >= 0) return i * t - j;
	}
	return -1;
}
ll n , t;
int main() {
	scanf("%lld%lld" , &n , &t);
	printf("%lld" , bsgs(10 , (9 * n + 1) % t , t));
}
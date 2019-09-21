#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define ll long long
template <typename Tp>
void read(Tp &x) {
	Tp f = 1;
	char c = getchar();
	x = 0;
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' &&  c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	x = x * f;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
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
ll num = 0, t = 0;
ll n, y, z, k, m, x, p, A, B, a, b;
std::map <ll, ll> h;
void init() {
	t = ceil(sqrt(p));
	ll flag = qpow(y, t, p), ans = flag;
	h[ans] = t;
	for (int i = 2; i <= t; i++) {
		ans = (ans * flag) % p;
		h[ans] = i * t;;
	}
}
ll bsgs() {
	ll f = 1;
	for (ll i = 0; i <= t; i++) {
		if (h[(f * A) % p]) {
			return h[(f * A) % p] - i;
		}
		f = (f * y) % p;
	}
}
int main() {
	scanf("%lld%lld%lld", &y, &p, &n);
	init();
	while (n--) {
		read(A), read(B);
		printf("%lld\n", qpow(B, bsgs(), p));
	}
}
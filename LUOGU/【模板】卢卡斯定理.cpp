#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
#define MAXN 1001010
#define MOD
namespace STman {
	template <typename Tp>
	inline void read(Tp &x) {
		#define C getchar()
		Tp f = 1;x = 0;
		char k = C;
		while (k < '0' || k > '9') {if (k == '-') f = -1; k = C;}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0'; k = C;}
		x = x * f;
		#undef C
	}
	template <typename Tp>
	inline void write(Tp x) {
		if (x < 0) putchar('-') , x = -x;
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
	template <typename Tp>
	inline Tp max(Tp a, Tp b) {
		if (a > b) return a;
		else return b;
	}
	template <typename Tp>
	inline Tp min(Tp a, Tp b) {
		if (a < b) return a;
		else return b;
	}
	template <typename Tp>
	inline void swap(Tp &a, Tp &b) {
		Tp t = a;
		a = b;
		b = t;
	}
	template <typename Tp>
	inline Tp abs(Tp &a) {
		if (a < 0) return -a;
		else return a;
	}
	inline void sp() {
		putchar(32);
	}
	inline void et() {
		putchar(10);
	}
}
using namespace STman;
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
	read(t);
	while (t--) {
		read(n), read(m), read(p);
		ft(n + m, p);
		write(Lucas(n + m, n, p)), et();
	}
}
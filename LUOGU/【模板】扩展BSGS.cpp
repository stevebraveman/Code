#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define ll long long
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
ll qpow(ll a , ll b , ll m) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return res % m;
}
ll bsgs(ll a , ll b , ll p) {
	std::map <ll , ll> h;
	h.clear();
	b %= p;
	ll t = sqrt(p) + 1;
	for (int i = 0 ; i < t ; i++) {
		ll v = b * qpow(a , i , p) % p;
		h[v] = i;
	}
	a = qpow(a , t , p);
	if (a == 0) return (b == 0) ? 1 : -1;
	for (int i = 0 ; i <= t ; i++) {
		int v = qpow(a , i , p);
		int j = h.find(v) == h.end() ? -1 : h[v];
		if (j >= 0 && i * t - j >= 0) return i * t - j;
	}
	return -1;
}
ll n , y , z , k , m , x , flag , p;
int main() {
	read(p), read(y), read(z);
	if (bsgs(y , z , p) == -1) {
		printf("no solution");
	}
	else {
		write(bsgs(y , z , p));
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define INF 2147483647
namespace STman {
	inline char gc(){
		#ifdef ONLINE_JUDGE
			static char now[1 << 16], *S, *T;
			if (T == S) {T = (S = now) + fread(now, 1, 1 << 16, stdin); if (T == S) return EOF;}
			return *S++;
		#else 
			return getchar();
		#endif
	}
	template <typename Tp>
	inline void read(Tp &x) {
		Tp f = 1;x = 0;
		char k = gc();
		while (k < '0' || k > '9') {if (k == '-') f = -1;k = gc();}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0';k = gc();}
		x = x * f;
	}
	template <typename Tp>
	inline void write(Tp x) {
		if (x < 0) putchar('-') , x = -x;
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
	template <typename Tp>
	inline Tp max(Tp a , Tp b) {
		if (a > b) return a;
		else return b;
	}
	template <typename Tp>
	inline Tp min(Tp a , Tp b) {
		if (a < b) return a;
		else return b;
	}
	template <typename Tp>
	inline void swap(Tp &a , Tp &b) {
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
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
ll phi(ll n) {
	ll res = n;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res = res / i * (i - 1);
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) res = res / n * (n - 1);
	return res;
}
ll qpow(ll a, ll b, ll p) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		b >>= 1;
		a = (a * a) % p;
	}
	return res % p;
}
ll a, p, l, tot = INF;
int main() {
	read(p), read(a);
	if (gcd(a, p) != 1) {
		puts("Let's go Blue Jays!");
		return 0;
	}
	else {
		l = phi(p);
		for (ll i = 1; i * i <= l; i++) {
			if (l % i == 0) {
				if (qpow(a, i, p) % p == 1) {
					tot = i;
					break;
				}
				if (qpow(a, l / i, p) % p == 1) {
					tot = min(tot, l / i);
				}
			}
		}
		write(tot);
		return 0;
	}
}
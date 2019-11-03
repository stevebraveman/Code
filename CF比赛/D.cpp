#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define ll long long
namespace STman {
	inline char gc(){
		// #ifdef ONLINE_JUDGE
		// 	static char now[1 << 16], *S, *T;
		// 	if (T == S) {T = (S = now) + fread(now, 1, 1 << 16, stdin); if (T == S) return EOF;}
		// 	return *S++;
		// #else 
			return getchar();
		// #endif
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
const int maxn = 1e5+5;
int n, k, _____;
ll ans;
int a[maxn], chk[maxn], p[maxn], ptot;
std::map<ll,int> hs;
inline void solve(ll a, int b, ll t) {
	int fl = 0;
	while (b) {
		if (b & 1) {
			if (fl) _____=1;
			t /= a;
			if (!t) _____=1;
		}
		b >>= 1;
		if (a > t / a) fl = 1;
		else a *= a;
	}
}
ll qpow(ll a, ll b) {
	ll res=1;
	while (b) {
		if (b & 1) res = res * a;
		b >>= 1;
		a = a * a;
	}
	solve(a, b, 1e5);
	return res;
}
void seive(int U) {
	for (int i = 2; i <= U; i++) {
		if (!chk[i]) {
			p[++ptot] = i;
		}
		for (int j = 1; j <= ptot && p[j] * i <= U; j++) {
			chk[p[j] * i] = 1;
			if(i % p[j] == 0) break;
		} 
	}
}
int main() {
	read(n);
	read(k);
	int U = std::ceil(sqrt(100000));
	seive(U);
	int x, y;
	for (int i = 1; i <= n; i++) {
		read(x);
		y = x;
		ll New = 1, h = 1;
		_____ = 0;
		for (int j = 1; j <= ptot; j++) {
			if (1LL * p[j] * p[j] > y) break;
			if (x % p[j]) continue;
			if (x == 1) break;
			int tot = 0;
			while (x % p[j] == 0) {
				x /= p[j];
				++tot;
			}
			tot %= k;
			if ((k - tot) % k >= 18) {
				_____ = 1;
			}
			else New *= qpow(p[j], (k - tot) % k);
			if (New > 1e6 || New < 0) {
				_____ = 1;
			}
			h *= qpow(p[j], tot);
		}
		if (x != 1) {
			h *= x;
			if ((k - 1) % k < 15) {
				New *= qpow(x, (k - 1) % k);
			}
			else _____ = 1;
			if (New > 1000000 || New < 0) _____ = 1;
		}
		if (!_____) ans += hs[New];
		hs[h]++;
	}
	write(ans), et();
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
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
ll ans1[20], ans2[20], t[20], f[20];
ll dp(ll n, ll *p) {
	ll l = 0, tot;
	ll a[20];
	while (n) {
		a[++l] = n % 10;
		n /= 10;
	}
	for (ll i = l; i >= 1; i--) {
		for (ll j = 0; j <= 9; j++) {
			p[j] += f[i - 1] * a[i];
		}
		for (ll j = 0; j < a[i]; j++) {
			p[j] += t[i - 1];
		}
		tot = 0;
		for (int j = i - 1; j >= 1; j--) {
			tot = tot * 10 + a[j];
		}
		p[a[i]] += tot + 1;
		p[0] -= t[i - 1];
	}
}
ll solve(ll l, ll r) {

}
ll l, r, p, q;
int main() {
	read(l), read(r);
	p = l, q = r;
	t[0] = 1;
	for (ll i = 1; i <= 14; i++) {
		f[i] = f[i - 1] * 10 + t[i - 1];
		t[i] = 10 * t[i - 1];
	}
	dp(l - 1, ans1);
	dp(r, ans2);
	for (int i = 0; i <= 9; i++) {
		write(ans2[i] - ans1[i]), sp();
	}
}
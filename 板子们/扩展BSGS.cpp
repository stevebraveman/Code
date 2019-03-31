#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <iostream>
#define ll long long
#define Fill(a, b) memset(a, b, sizeof(a))
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
std::map <int, int> pw;
int gcd(int x, int y) {
	return (!y) ? x : gcd(y, x % y);
}
int qpow(ll x, ll y, int p) {
	ll ret = 1;
	for(; y; x = x * x % p, y >>= 1) if(y & 1) ret = ret * x % p;
	return ret;
}
int a, b, p;
int bsgs() {
	if(b == 1) return 0;
	pw.clear();
	int cnt = 0, t = 1, s, x, m;
	for(int d = gcd(a, p); d != 1; d = gcd(a, p)) {
		if(b % d) return -1;
		++cnt, b /= d, p /= d, t = 1LL * t * a / d % p;
		if(b == t) return cnt;
	}
	s = b, m = sqrt(p) + 1;
	for(int i = 0; i < m; ++i) {
		pw[s] = i;
		s = 1LL * s * a % p;
	}
	x = qpow(a, m, p), s = t;
	for(int i = 1; i <= m; ++i) {
		s = 1LL * s * x % p;
		if(pw.count(s)) return i * m - pw[s] + cnt;
	}
	return -1;
}
int ans;
int main() {
	while (1) {
		read(a), read(p), read(b);
		if (!(a + p + b)) {
			break;
		}
		a %= p, b %= p, ans = bsgs();
		if (ans < 0) {
			puts("No Solution");
		}
		else {
			printf("%d\n", ans);
		}
	}
	return 0;
}

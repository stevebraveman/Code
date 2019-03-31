#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstring>
#define ll long long
#define MAXN 2000005
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
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
struct Segtree {
	ll a[MAXN] , b[MAXN << 2] , lazy[MAXN << 2];
	inline void pd(ll p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	void build(ll l , ll r , ll p) {
		if (l == r) {
			b[p] = a[l];
			return;
		}
		ll m = (l + r) >> 1;
		build(l , m , ls(p));
		build(m + 1 , r , rs(p));
		pd(p);
	}
	inline void pushd(ll p , ll l) {
		if (lazy[p]) {
			lazy[ls(p)] ^= 1;
			lazy[rs(p)] ^= 1;
			b[ls(p)] = (l - (l >> 1)) - b[ls(p)];
			b[rs(p)] = (l >> 1) - b[rs(p)];
			lazy[p] = 0;
		}
	}
	void up(ll x , ll y , ll l , ll r , ll p) {
		pushd(p , r - l + 1);
		if (x <= l && y >= r) {
			lazy[p] ^= 1;
			b[p] = r - l + 1 - b[p];
			return;
		}
		ll m = (l + r) >> 1;
		if (x <= m) up(x , y , l , m , ls(p));
		if (y > m) up(x , y , m + 1 , r , rs(p));
		pd(p);
	}
	ll sum(ll x , ll y , ll l , ll r , ll p) {
		ll s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		pushd(p , r - l + 1);
		ll m = (l + r) >> 1;
		if (x <= m) s += sum(x , y , l , m , ls(p));
		if (y > m) s += sum(x , y , m + 1 , r , rs(p));
		return s;
	}
}tree;
ll n , m , l , r , k;
char s;
int main() {
	read(n), read(m);
	tree.build(1 , n , 1);
	while (m--) {
		read(k);
		if (k == 1) {
			read(l), read(r);
			tree.up(l , r , 1 , n , 1);
		}
		else {
			read(l);
			write(tree.sum(l , l , 1 , n , 1)), et();
		}
	}
}

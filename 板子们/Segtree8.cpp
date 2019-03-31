#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define ll long long
namespace STman {
	template <typename Tp>
	inline void read(Tp &x) {
		#define C getchar()
		Tp f = 1;x = 0;
		char k = C;
		while (k < '0' || k > '9') {if (k == '-') f = -1;k = C;}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0';k = C;}
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
	inline Tp max(Tp a , Tp b) {
		if (a > b) return a;
		else return b;
	}
	template <typename Tp>
	inline Tp min(Tp a , Tp b) {
		if (a < b) return a;
		else return b;
	}
	inline void sp() {
		putchar(32);
	}
	inline void et() {
		putchar(10);
	}
}
using namespace STman;
struct Segment {
	ll a[MAXN] , b[MAXN << 2] , lazy[MAXN << 2];
	void pd(ll p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	void build(ll l , ll r , ll p) {
		lazy[p] = 0;
		if (l == r) {
			b[p] = a[l];
			return;
		}
		ll m = (l + r) >> 1;
		build(l , m , ls(p));
		build(m + 1 , r , rs(p));
		pd(p);
	}
	void f(ll l , ll r , ll p , ll k) {
		b[p] += k * (r - l + 1);
		lazy[p] += k;
	}
	void pushd(ll l , ll r , ll p) {
		ll m = (l + r) >> 1;
		f(l , m , ls(p) , lazy[p]);
		f(m + 1 , r , rs(p) , lazy[p]);
		lazy[p] = 0;
	}
	void update(ll x , ll y , ll l , ll r , ll p , ll k) {
		if (x <= l && y >= r) {
			b[p] += k * (r - l + 1);
			lazy[p] += k;
			return;
		}
		pushd(l , r , p);
		ll m = (l + r) >> 1;
		if (x <= m) update(x , y , l , m , ls(p) , k);
		if (y > m) update(x , y , m + 1 , r , rs(p) , k);
		pd(p);
	}
	ll sum(ll x , ll y , ll l , ll r , ll p) {
		ll s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		pushd(l , r , p);
		ll m = (l + r) >> 1;
		if (x <= m) s += sum(x , y , l , m , ls(p));
		if (y > m) s += sum(x , y , m + 1 , r , rs(p));
		return s;
	}
}tree;
ll n , m , l , r , k , op;
int main() {
	read(n);
	read(m);
	for (int i = 1 ; i <= n ; i++) {
		read(tree.a[i]);
	}
	tree.build(1 , n , 1);
	for (int i = 1 ; i <= m ; i++) {
		read(op);
		if (op == 1) {
			read(l) , read(r) , read(k);
			tree.update(l , r , 1 , n , 1 , k);
		}
		else {
			read(l) , read(r);
			write(tree.sum(l , r , 1 , n , 1)) , et();
		}
	}
}
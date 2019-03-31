#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10010
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
struct Edge {
	int v, nx, w;
}e[MAXN];
int head[MAXN], ecnt, n, m, x, y, l, r, k;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct Segtree {
	int lazy[MAXN << 2] , a[MAXN] , b[MAXN << 2], pm;
	inline void pd(int p) {
		b[p] = b[rs(p)] + b[ls(p)];
	}
	void build(int l , int r , int p) {
		lazy[p] = 0;
		if (l == r) {
			b[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(l , m , ls(p));
		build(m + 1 , r , rs(p));
		pd(p);
	}
	inline void f(int p , int l , int r , int k) {
		lazy[p] += k;
		b[p] += k * (r - l + 1);
	}
	void pushd(int l , int r , int p) {
		int m = (l + r) >> 1;
		f(ls(p) , l , m , lazy[p]);
		f(rs(p) , m + 1 , r , lazy[p]);
		lazy[p] = 0;
	}
	void update(int x , int y , int l , int r , int p , int k) {
		if (x <= l && y >= r) {
			lazy[p] += k;
			b[p] += k * (r - l + 1);
			return;
		}
		pushd(l , r , p);
		int m = (l + r) >> 1;
		if (x <= m) update(x , y , l , m , ls(p) , k);
		if (y > m) update(x , y , m + 1 , r , rs(p) , k);
		pd(p);
	}
	int sum(int x , int y , int l , int r , int p) {
		int s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		int m = (l + r) >> 1;
		pushd(l , r , p);
		if (x <= m) s += sum(x , y , l , m , ls(p)) % pm;
		if (y > m) s += sum(x , y , m + 1 , r , rs(p)) % pm;
		return s % pm;
	}
}tree;
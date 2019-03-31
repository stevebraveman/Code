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
struct fhq_treap {
	int l, r;
	int val;
	int rd;
	int size;
}a[MAXN];
int tot = 0, root = 0;
inline void update(int x) {
	a[x].size = a[a[x].r].size + a[a[x].l].size + 1
}
int newnode(int v) {
	tot++;
	a[tot].size = 1;a[tot].v = v;a[tot].rd = rand();
	return tot;
}
int merge(int x, int y) {
	if (!x || !y) return x + y;
	if (a[x].rd < a[y].rd) {
		a[x].r = merge(a[x].r, y);
		update(x);
		return x;
	}
	else {
		a[y].l = merge(x, a[y].l);
		update(y);
		return y;
	}
}
void split(int n, int k, int &x, int &y) {
	if (!n) {
		x = y = 0;
	}
	else {
		if (val[now] <= k) {
			x = n;
			split(a[n].r, k, a[n].r, y);
		}
		else {
			y = n;
			split(a[n].l, k, x, a[i].l);
		}
		update(n);
	}
}
int kth(int n, int k) {
	while (1) {
		if (k <= a[a[n].l].size) n = a[n].l;
		else {
			if (k == a[a[n].l].size + 1) return n;
			else {
				k -= a[a[n].l]
			}
		}
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
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
bool p1;
struct Treap {
	int l, r;
	int val, dat;
	int cnt, size;
}a[MAXN];
int tot, root, n, INF = 19260817;
bool p2;
int New(int val) {
	a[++tot].val = val;
	a[tot].dat = rand();
	a[tot].cnt = a[tot].size = 1;
	return tot;
}
void update(int p) {
	a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
}
void Build() {
	New(-INF), New(INF);
	root = 1, a[1].r = 2;
	update(root);
}
int FindR(int p, int val) {
	if (p == 0) return 0;
	if (val == a[p].val) return a[a[p].l].size + 1;
	if (val < a[p].val) return FindR(a[p].l, val);
	return FindR(a[p].r, val) + a[a[p].l].size + a[p].cnt;
}
int FindN(int p, int r) {
	if (p == 0) return 0;
	if (a[a[p].l].size >= r) return FindN(a[p].l, r);
	if (a[a[p].l].size + a[p].cnt >= r) return a[p].val;
	return FindN(a[p].r, r - a[a[p].l].size - a[p].cnt);
}
void zig(int &p) {
	int q = a[p].l;
	a[p].l = a[q].r, a[q].r = p, p = q;
	update(a[p].r), update(p);
}
void zag(int &p) {
	int q = a[p].r;
	a[p].r = a[q].l, a[q].l = p, p = q;
	update(a[p].l), update(p);
}
void insert(int &p, int val) {
	if (p == 0) {
		p = New(val);
		return;
	}
	if (val == a[p].val) {
		a[p].cnt++, update(p);
		return;
	}
	if (val < a[p].val) {
		insert(a[p].l, val);
		if (a[p].dat < a[a[p].l].dat) zig(p);
	}
	else {
		insert(a[p].r, val);
		if (a[p].dat < a[a[p].r].dat) zag(p);
	}
	update(p);
}
int Pre(int val) {
	int ans = 1;
	int p = root;
	while (p) {
		if (val == a[p].val) {
			if (a[p].l > 0) {
				p = a[p].l;
				while (a[p].r > 0) p = a[p].r;
				ans = p;
			}
			break;
		}
		if (a[p].val < val && a[p].val > a[ans].val) ans = p;
		p = val < a[p].val ? a[p].l : a[p].r;
	}
	return a[ans].val;
}
int Next(int val) {
	int ans = 2;
	int p = root;
	while (p) {
		if (val == a[p].val) {
			if (a[p].r) {
				p = a[p].r;
				while (a[p].l) p = a[p].l;
				ans = p;
			}
			break;
		}
		if (a[p].val > val && a[p].val < a[ans].val) ans = p;
		p = val < a[p].val ? a[p].l : a[p].r;
	}
	return a[ans].val;
}
void Remove(int &p, int val) {
	if (p == 0) return;
	if (val == a[p].val) {
		if (a[p].cnt > 1) {
			a[p].cnt--, update(p);
			return;
		}
		if (a[p].l || a[p].r) {
			if (a[p].r == 0 || a[a[p].l].dat > a[a[p].r].dat)
				zig(p), Remove(a[p].r, val);
			else
				zag(p), Remove(a[p].l, val);
			update(p);
		}
		else p = 0;
		return;
	}
	val < a[p].val ? Remove(a[p].l, val) : Remove(a[p].r, val);
	update(p);
}
int op, x;
int main() {
	Build();
	read(n);
	while (n--) {
		read(op), read(x);
		switch(op) {
			case 1: {
				insert(root, x);
				break;
			}
			case 2: {
				Remove(root, x);
				break;
			}
			case 3: {
				write(FindR(root, x) - 1), et();
				break;
			}
			case 4: {
				write(FindN(root, x + 1)), et();
				break;
			}
			case 5: {
				write(Pre(x)), et();
				break;
			}
			case 6: {
				write(Next(x)), et();
				break;
			}
		}
	}
}
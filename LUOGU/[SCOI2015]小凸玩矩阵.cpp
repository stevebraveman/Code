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
struct Edge {
	int v, nx, w;
}e[MAXN];
int head[MAXN], mch[MAXN / 100], ecnt, n, m, k, vis[MAXN / 10], l, r, mid, cnt, a, limi = 0;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
bool Hungary(int k, int t, int w) {
	for (int i = head[k]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to] != t && e[i].w <= w) {
			vis[to] = t;
			if (!mch[to] || Hungary(mch[to], t, w)) {
				mch[to] = k;
				return 1;
			}
		}
	}
	return 0;
}
int check(int lim) {
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	memset(mch, 0, sizeof(mch));
	for (int i = 1; i <= n; i++) {
		if (Hungary(i, i, lim)) ans++;
	}
	return ans;
}
int main() {
	read(n), read(m), read(k);
	k = n - k + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			read(a);
			add(i, j, a);
			limi = max(a, limi);
		}
	}
	l = 1, r = limi;
	while (l < r) {
		mid = (l + r) >> 1;
		if (check(mid) >= k) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	write(l);
	return 0;
}
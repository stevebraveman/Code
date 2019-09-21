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
	int v, nx;
}e[MAXN];
int ecnt, head[MAXN], n, t, vis[MAXN], mch[MAXN], tot, a, ans;
bool ifs[MAXN], ifz[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
bool Hungary(int k, int t) {
	for (int i = head[k]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to] != t) {
			vis[to] = t;
			if (!mch[to] || Hungary(mch[to], t)) {
				mch[to] = k;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	read(t);
	while (t--) {
		read(n);
		// std::cin >> n;
		tot = 0;
		ecnt = 0;
		ans = 0;
		memset(head, 0, sizeof(head));
		for (int i = 1; i <= n; i++) {
			read(ifs[i]);
			// std::cin >> ifs[i];
		}
		for (int i = 1; i <= n; i++) {
			read(ifz[i]);
			// std::cin >> ifz[i];
			if (!ifz[i] && ifs[i]) {
				add(i, i);
			}
		}
		memset(mch, 0, sizeof(mch));
		for (int i = 1; i <= n; i++) {
			if (!ifs[i] || (ifs[i] && !ifz[i])) {
				tot++;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				read(a);
				if (a && ifs[j]) {
					add(i, j);
				}
			}
		}
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			if ((ifs[i] && ifz[i] == 0) || !ifs[i]) {
				if (Hungary(i, i)) {
					ans++;
				}
			}
		}
		// write(ans), et();
		// write(tot), et();
		if (ans == tot) {
			puts("^_^");
		}
		else {
			puts("T_T");
		}
	}
}
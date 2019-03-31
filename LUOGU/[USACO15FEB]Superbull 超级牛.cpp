#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 4001000
#define int long long
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
	int u, v, w;
}e[MAXN];
int b[MAXN], fa[MAXN], ecnt, ans, n, cnt;
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
void un(int a, int b) {
	a = find(a);
	b = find(b);
	fa[a] = b;
}
bool cmp(Edge a, Edge b) {
	return a.w > b.w;
}
signed main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(b[i]);
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			e[++ecnt] = (Edge) {i, j, (b[i] ^ b[j])};
		}
	}
	for (int i = 1; i <= n * n; i++) {
		fa[i] = i;
	}
	std::sort(e + 1, e + ecnt + 1, cmp);
	for (int i = 1; i <= ecnt; i++) {
		if (find(e[i].u) != find(e[i].v)) {
			un(e[i].u, e[i].v);
			ans += e[i].w;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	write(ans);
	return 0;
}
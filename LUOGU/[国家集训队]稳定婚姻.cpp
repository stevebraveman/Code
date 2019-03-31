#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#define MAXN 4000100
std::map<std::string, int> h;
std::string g, b;
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
int head[MAXN], ecnt, n, m, in[MAXN], dfn[MAXN], low[MAXN], tim, num, hd, st[MAXN];
bool vis[MAXN];
inline void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++hd] = u;
	vis[u] = 1;
	for (int i = head[u] ; i ; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[v] , low[u]);
		}
		else if (vis[v]) low[u] = min(dfn[v] , low[u]);
	}
	if (dfn[u] == low[u]) {
		num++;
		int v;
		do {
			v = st[hd--];
			vis[v] = 0;
			in[v] = num;
		} while (v != u);
	}
}
int main() {
	// read(n);
	memset(vis, 0, sizeof(vis));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		std::cin >> g >> b;
		h[g] = i;
		h[b] = i + n;
		add(h[g], h[b]);
	}
	// read(m);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		std::cin >> g >> b;
		add(h[b], h[g]);
	}
	for (int i = 1; i <= n * 2; i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == in[i + n]) {
			puts("Unsafe");
		}
		else {
			puts("Safe");
		}
	}
	return 0;
}
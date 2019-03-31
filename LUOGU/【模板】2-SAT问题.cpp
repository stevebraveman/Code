#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10000100
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
int head[MAXN], ecnt, n, tim, num, in[MAXN], m, u, v, st[MAXN], dfn[MAXN], low[MAXN], top;
bool fu, fv, vis[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		num++;
		int v;
		do {
			v = st[top];
			top--;
			in[v] = num;
			vis[v] = 0;
		} while (u != v);
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(u), read(fu), read(v), read(fv);
		add(u + n * (fu & 1), v + n * (fv ^ 1));
		add(v + n * (fv & 1), u + n * (fu ^ 1));
	}
	for (int i = 1; i <= n * 2; i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == in[i + n]) {
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	puts("POSSIBLE");
	for (int i = 1; i <= n; i++) {
		write((in[i] < in[i + n])), sp();
	}
	et();
}
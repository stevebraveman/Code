#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 5001000
#define INF 19260817
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
int head[MAXN], ecnt, n, m, x[MAXN], y[MAXN], a[MAXN], mi[MAXN], p[MAXN], k;
int dfn[MAXN], low[MAXN], st[MAXN], top, in[MAXN], num, ent[MAXN], tim;
static long long ans;
bool vis[MAXN];
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
			v = st[top--];
			vis[v] = 0;
			in[v] = num;
			if (p[v] < p[mi[num]]) mi[num] = v; 
		} while (u != v);
	}
}
bool cmp(int a, int b) {
	return a > b;
}
signed main() {
	read(n), read(m), read(k);
	p[0] = INF;
	for (int i = 1; i <= n; i++) {
		read(p[i]);
	}
	for (int i = 1; i <= m; i++) {
		read(x[i]), read(y[i]);
		add(x[i], y[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= m; i++) {
		if (in[x[i]] != in[y[i]]) {
			ent[in[y[i]]]++;
		}
	}
	for (int i = 1; i <= num; i++) {
		if (!ent[i]) p[mi[i]] = 0;
	}
	std::sort(p + 1, p + 1 + n, cmp);
	for (int i = 1; i <= k; i++) {
		ans += (long long)(p[i]);
	}
	write(ans), et();
	return 0;
}
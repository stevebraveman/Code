#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1001010
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
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int f, v, nx;
}e[MAXN], ef[MAXN];
int head[MAXN], ecnt, n, m, dfn[MAXN], low[MAXN], num, tim, top, tot;
int in[MAXN], ent[MAXN], si[MAXN], x, y, out[MAXN], h[MAXN], ect, st[MAXN];
bool vis[MAXN], vi[MAXN], flag;
void add(int f, int t) {
	e[++ecnt] = (Edge) {f, t, head[f]};
	head[f] = ecnt;
}
void add_e(int f, int t) {
	ef[++ect] = (Edge) {f, t, h[f]};
	h[f] = ect;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[v], low[u]);
		}
		else if (vis[v]) low[u] = min(dfn[v], low[u]);
	}
	if (dfn[u] == low[u]) {
		num++;
		int v;
		do {
			v = st[top--];
			in[v] = num;
			vis[v] = 0;
			si[num]++;
		} while (u != v);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= ecnt; i++) {
		int u = e[i].f, v = e[i].v;
		if (in[u] != in[v]) {
			add_e(in[u], in[v]);
			ent[in[v]]++;
		}
	}
	for (int i = 1; i <= num; i++) {
		if (!flag && !ent[i] && si[i] == 1) {
			int rd = 0;
			for (int j = h[i]; j; j = ef[j].nx) {
				int to = ef[j].v;
				if (ent[to] == 1) rd = 1;
			}
			if (!rd) flag = 1;
		}
		if (!ent[i]) tot++;
	}
	if (flag) tot--;
	printf("%.6f\n", 1.0 - (double)tot / (double)n);
	return 0;
}
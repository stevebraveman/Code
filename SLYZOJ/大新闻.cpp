#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define LOG 30
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
int head[MAXN], ecnt, dfn[MAXN], in[MAXN], st[MAXN], q, f, g;
int top, num, n, m, x[MAXN], y[MAXN], low[MAXN], tim, dis[MAXN];
int anc[MAXN << 1][LOG], dep[MAXN << 1], len;
bool vis[MAXN], a[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (v == fa) continue;
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		int v;
		num++;
		do {
			v = st[top--];
			in[v] = num;
		} while (u != v);
	}
}
void dfs(int u, int p, int d) {
	anc[u][0] = p;
	dep[u] = d;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == p) continue;
		dis[to] = dis[u] + e[i].w;
		dfs(to, u, d + 1);
	}
}
inline void init(int r, int n) {
	dfs(r, 0, 1);
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		}
	}
}
inline int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x , y);
	int h = dep[x] - dep[y];
	for (int i = 0; h > 0; i++) {
		if (h & 1) x = anc[x][i];
		h >>= 1;
	}
	if (x == y) return x;
	for (int i = LOG - 1; i >= 0; i--) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		add(x[i], y[i], 1);
		add(y[i], x[i], 1);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i, -1);
	}
	memset(vis, 0, sizeof(vis));
	memset(head, 0, sizeof(head));
	memset(e, 0, sizeof(e));
	ecnt = 0;
	for (int i = 1; i <= m; i++) {
		if (in[x[i]] != in[y[i]]) {
			add(in[x[i]], in[y[i]], 1);
			add(in[y[i]], in[x[i]], 1);
		}
	}
	init(1, num);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &f, &g);
		int ws = 0;
		f = in[f];
		g = in[g];
		if (f == g) {
			puts("Angry!");
		}
		else printf("%d\n", dis[f] + dis[g] - 2 * dis[LCA(f, g)]);
	}
}
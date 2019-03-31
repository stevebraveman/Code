#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MOD 1000000000
#define MAXN 100010
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
}e[MAXN], ef[MAXN];
int head[MAXN], ecnt, n, m, dfn[MAXN], low[MAXN], tim, st[MAXN], top, num;
int in[MAXN], x, y, ans, nm[MAXN], tot[MAXN], h[MAXN], a[MAXN];
bool vis[MAXN], vis2[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
	ef[ecnt] = (Edge) {f, h[t]};
	h[t] = ecnt;
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
	if (dfn[u] == low[u]) {
		num++;
		int v;
		do {
			v = st[top--];
			vis[v] = 0;
			in[v] = num;
		} while (v != u);
	}
}
int bfs() {
	std::queue <int> q;
	q.push(1);
	vis[1] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (!vis[to]) {
				vis[to] = 1;
				q.push(to);
			}
			nm[to]++;
		}
	}
	while (!q.empty()) {
		q.pop();
	}
	q.push(2);
	vis2[2] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = h[u]; i; i = ef[i].nx) {
			int to = ef[i].v;
			if (!vis2[to]) {
				vis2[to] = 1;
				q.push(to);
			}
		}
	}
	while (!q.empty()) {
		q.pop();
	}
	for (int i = 1; i <= n; i++) {
		a[in[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] && vis2[i] && a[in[i]] != 1) {
			return -1;
		}
	}
	tot[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (vis2[to]) {
				tot[to] = (tot[to] + tot[u]) % MOD;
				if(!--nm[to]) q.push(to);
			}
		}
	}
	return tot[2];
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(x), read(y);
		add(x, y);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	memset(vis, 0, sizeof(vis));
	ans = bfs();
	if (ans == -1) {
		puts("inf");
		return 0;
	}
	write(ans);
}
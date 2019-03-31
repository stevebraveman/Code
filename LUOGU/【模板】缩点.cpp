#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
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
	int u, v, nx;
}e[MAXN], ep[MAXN];
int head[MAXN], ecnt, n, m, x, y, dfn[MAXN], low[MAXN], tim, in[MAXN];
int st[MAXN], top, ent[MAXN], num, p[MAXN], dis[MAXN], ecntt, hd[MAXN];
bool vis[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {f, t, head[f]};
	head[f] = ecnt;
}
void add_e(int f, int t) {
	ep[++ecntt] = (Edge) {f, t, hd[f]};
	hd[f] = ecntt;
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
		int v;
		while (1) {
			v = st[top--];
			in[v] = u;
			vis[v] = 0;
			if (u == v) break;
			p[u] += p[v];
		}
	}
}
int topo() {
	std::queue <int> q;
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		if (in[i] == i && !ent[i]) {
			q.push(i);
			dis[i] = p[i];
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = hd[u]; i; i = ep[i].nx) {
			int to = ep[i].v;
			dis[to] = max(dis[to], dis[u] + p[to]);
			ent[to]--;
			if (ent[to] == 0) q.push(to);
		}
	}
	for (int i = 1; i <= n; i++) {
		tot = max(tot, dis[i]);
	}
	return tot;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(p[i]);
	}
	for (int i = 1; i <= m; i++) {
		read(x), read(y);
		add(x, y);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= ecnt; i++) {
		int u = in[e[i].u], v = in[e[i].v];
		if (u != v) {
			add_e(u, v);
			ent[v]++;
		}
	}
	write(topo());
}
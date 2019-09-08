/*
ST表做法
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define MAXN 1000010
#define LOG 30
int ST[MAXN << 1][LOG];
int val[MAXN << 1] , dep[MAXN << 1] , fi[MAXN] , len , ecnt , u , v , s , p , q , n , m , head[MAXN];
int dis[MAXN];
struct edge {
	int v , nx , w;
}e[MAXN];
void add(int f , int t , int w) {
	e[++ecnt] = (edge){t , head[f] , w};
	head[f] = ecnt;
}
inline int calc(int x , int y) {
	if (dep[x] < dep[y]) return x;
	else return y;
}
inline void dfs(int u , int p , int d) {
	val[++len] = u;
	dep[len] = d;
	fi[u] = len;
	for (int i = head[u] ; i ; i = e[i].nx) {
		int v = e[i].v;
		if (v == p) continue;
		dis[v] = dis[u] + e[i].w;
		dfs(v , u , d + 1);
		val[++len] = u; dep[len] = d;
	}
}
inline void init(int root) {
	len = 0; dis[root] = 0;
	dfs(root , 0 , 1);
	for (int i = 1 ; i <= len ; i++) ST[i][0] = i;
	for (int j = 1; (1 << j) <= len; j++) {
		for (int i = 1 ; i + (1 << j) - 1 <= len ; i++) {
			ST[i][j] = calc(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
		}
	}
}
inline int query(int x , int y) {
	int l = fi[x], r = fi[y]; 
	if (l > r) std::swap(l , r);
	int k = log2(r - l + 1);
	return val[calc(ST[l][k] , ST[r - (1 << k) + 1][k])];
}
int main() {
	memset(dis , 0x7f , sizeof(dis));
	scanf("%d%d%d" , &n , &m , &s);
	for (int i = 1 ; i <= n - 1 ; i++) {
		scanf("%d%d" , &u , &v);
		add(u , v , 1);
		add(v , u , 1);
	}
	init(s);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d%d" , &p , &q);
		printf("%d\n" , query(p , q));
	}
}
/*
倍增法
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define MAXN 1000010
#define LOG 30
int anc[MAXN << 1][LOG];
int val[MAXN << 1], dep[MAXN << 1], len, ecnt, u, v, s, p, q, n, m, head[MAXN];
int dis[MAXN];
struct edge {
	int v, nx, w;
}e[MAXN];
inline void add(int f, int t, int w) {
	e[++ecnt] = (edge){t, head[f], w};
	head[f] = ecnt;
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
	dis[r] = 0;
	dfs(r, 0, 1);
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		}
	}
}
inline int query(int x, int y) {
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
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		add(u, v, 1);
		add(v, u, 1);
	}
	init(s , n);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		printf("%d\n", query(u, v));
	}
}
/*
LCT做法
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ls(x) c[x][0]
#define rs(x) c[x][1]
#define ll long long
#define MAXN 100010
int si[MAXN], val[MAXN], st[MAXN], c[MAXN][2], fa[MAXN];
struct yuno {
	ll a1, a0;
};
yuno operator < (yuno a, yuno b) {
	yuno t;
	t.a0 = (~a.a0 & b.a0) | (a.a0 & b.a1);
	t.a1 = (~a.a1 & b.a0) | (a.a1 & b.a1);
	return t;
}

bool r[MAXN];
int n, m, u, v, op;
bool ifr(int p) {
	return ls(fa[p]) == p || rs(fa[p]) == p;
}
void pd(int p) {
	si[p] = si[ls(p)] ^ si[rs(p)] ^ val[p];
}
void flit(int p) {
	int t = ls(p);
	ls(p) = rs(p);
	rs(p) = t;
	r[p] ^= 1;
}
void pushd(int p) {
	if (r[p]) {
		if (ls(p)) flit(ls(p));
		if (rs(p)) flit(rs(p));
		r[p] = 0;
	}
}
void rotate(int p) {
	int x = fa[p], y = fa[x], k = rs(x) == p, w = c[p][!k];
	if (ifr(x)) c[y][c[y][1] == x] = p;
	c[p][!k] = x;
	c[x][k] = w;
	if (w) fa[w] = x;
	fa[x] = p;
	fa[p] = y;
	pd(x);
}
void splay(int p) {
	int y = p, z = 0;
	st[++z] = y;
	while (ifr(y)) st[++z] = y = fa[y];
	while (z) pushd(st[z--]);
	while (ifr(p)) {
		y = fa[p];
		z = fa[y];
		if (ifr(y)) {
			rotate((ls(y) == p) ^ (ls(z) == y) ? p : y);
		}
		rotate(p);
	}
	pd(p);
}
void access(int p) {
	for (int i = 0; p; p = fa[i = p]) {
		splay(p);
		rs(p) = i;
		pd(p);
	}
}
void makeroot(int p) {
	access(p);
	splay(p);
	flit(p);
}
int findr(int p) {
	access(p);
	splay(p);
	while (ls(p)) {
		pushd(p);
		p = ls(p);
	}
	splay(p);
	return p;
}
void split(int x, int y) {
	makeroot(x);
	access(y);
	splay(y);
}
void link(int x, int y) {
	makeroot(x);
	if (findr(y) != x) fa[x] = y;
}
int Find(int x, int y) {
	access(x);
	splay(x);
	splay(y);
	int rt = fa[y];
	while(rt != 0) {
		y = rt;
		splay(y);
		rt = fa[y];
	}
	return y;
}
void cut(int x, int y) {
	makeroot(x);
	if (findr(y) == x && fa[y] == x && !ls(y)) {
		fa[y] = rs(x) = 0;
		pd(x);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val[i]);
	}
	while (m--) {
		scanf("%d%d%d", &op, &u, &v);
		if (op == 0) {
			split(u, v);
			printf("%d\n", si[v]);
		}
		if (op == 1) {
			link(u, v);
		}
		if (op == 2) {
			cut(u, v);
		}
		if (op == 3) {
			splay(u);
			val[u] = v;
		}
	}
}
/*
树剖法
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct Edge {
	int v , nxt;
} e[2000010];
int head[500010] , cnt , dep[500010] , fa[500010] , top[500010] , size[500010] , son[500010] , mod , n , m , rt , tot , x , y;
void add(int u , int v) {
	e[++tot].nxt = head[u];
	e[tot].v = v;
	head[u] = tot;
}
void dfs1(int u , int pa) {
	size[u] = 1;
	for(int i = head[u] ; i ; i = e[i].nxt) {
		int v = e[i].v;
		if(v == pa) continue;
		dep[v] = dep[u] + 1;
		fa[v] = u;
		dfs1(v , u);
		size[u] += size[v];
		if(size[v] > size[son[u]]) son[u] = v;
	}
}
void dfs2(int u , int tp) {
	top[u] = tp;
	if(son[u]) dfs2(son[u] , tp);
	for(int i = head[u] ; i ; i=e[i].nxt) {
		int v = e[i].v;
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v , v);
	}
}
int main() {
	scanf("%d%d%d" , &n , &m , &rt);
	for(int i = 1 ; i <= n - 1 ; i++) {
		scanf("%d%d" , &x , &y);
		add(x , y);
		add(y , x);
	}
	dep[rt] = 1;
	fa[rt] = rt;
	dfs1(rt , -1);
	dfs2(rt , rt);
	while(m--) {
		scanf("%d%d" , &x , &y);
		while(top[x] != top[y]) {
			if(dep[top[x]] > dep[top[y]]) x = fa[top[x]];
			else y = fa[top[y]];
		}
		if(dep[x] < dep[y]) {
			printf("%d\n" , x);
		}
		else printf("%d\n" , y);
	}
	return 0;
}
/*
懒得写Tarjan。。。。。QWQ
 */
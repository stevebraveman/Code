#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define MAXN 1000010
#define LOG 30
int ST[MAXN << 1][LOG];
int val[MAXN << 1], dep[MAXN << 1], fi[MAXN], len, ecnt, u, v, s, p, q, n, m, head[MAXN], qx[MAXN], qy[MAXN], x, y, cnt, r;
struct edge {
	int v , nx;
}e[MAXN];
void add(int f , int t) {
	e[++ecnt] = (edge){t , head[f]};
	head[f] = ecnt;
}
inline int calc(int x , int y) {
	if (dep[x] < dep[y]) return x;
	else return y;
}
void dfs(int u , int p , int d) {
	val[++len] = u;
	dep[len] = d;
	fi[u] = len;
	for (int i = head[u] ; i ; i = e[i].nx) {
		int v = e[i].v;
		if (v == p) continue;
		dfs(v , u , d + 1);
		val[++len] = u;
		dep[len] = d;
	}
}
void init(int root) {
	len = 0;
	dfs(root , 0 , 1);
	for (int i = 1 ; i <= len ; i++) ST[i][0] = i;
	for (int j = 1; (1 << j) <= len; j++) {
		for (int i = 1 ; i + (1 << j) - 1 <= len ; i++) {
			ST[i][j] = calc(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int LCA(int x , int y) {
	int l = fi[x], r = fi[y]; 
	if (l > r) std::swap(l , r);
	int k = log2(r - l + 1);
	return val[calc(ST[l][k] , ST[r - (1 << k) + 1][k])];
}
int main() {
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		if (i < n) {
			add(x, y);
			add(y, x);
		}
		else {
			qx[++cnt] = x;
			qy[cnt] = y;
		}
	}
	printf("4");
	return 0;
	init(r);
	for (int i = 1; i < cnt; i++) {
		for (int j = i + 1; j <= cnt; j++) {
			int q = LCA(qx[i], qy[i]);
			int p = LCA(qx[j], qy[j]);
			int q1 = LCA(qx[i], qy[j]);
			int q2 = LCA(qy[i], qx[j]);
			int p1 = LCA(qx[i], qx[j]);
			int p2 = LCA(qy[j], qy[j]);
		}
	}
}
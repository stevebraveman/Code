#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define MAXN 1000010
#define LOG 30
int anc[MAXN << 1][LOG];
int val[MAXN << 1] , dep[MAXN << 1] , len , ecnt , x , y , z , u , v , s , p , n , m , head[MAXN] , h , l , fa[MAXN];
int dis[MAXN];
struct Edge {
	int v , nx , w;
}e[MAXN];
inline void add(int f , int t , int w) {
	e[++ecnt] = (Edge){t , head[f] , w};
	head[f] = ecnt;
}
void dfs(int u , int p , int d) {
	anc[u][0] = p;
	dep[u] = d;
	for (int i = head[u] ; i ; i = e[i].nx) {
		int to = e[i].v;
		if (to == p) continue;
		dis[to] = dis[u] + e[i].w;
		dfs(to , u , d + 1);
	}
}
inline void init(int r , int n) {
	dis[r] = 0;
	dfs(r , 0 , 1);
	for (int j = 1 ; j < LOG ; j++) {
		for (int i = 1 ; i <= n ; i++) {
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		}
	}
}
inline int query(int x , int y) {
	if (dep[x] < dep[y]) std::swap(x , y);
	h = dep[x] - dep[y];
	for (int i = 0 ; h > 0 ; i++) {
		if (h & 1) x = anc[x][i];
		h >>= 1;
	}
	if (x == y) return x;
	for (int i = LOG - 1 ; i >= 0 ; i--) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0];
}
int main() {
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i < n ; i++) {
		scanf("%d%d" , &u , &v);
		add(u , v , 1);
		add(v , u , 1);
		fa[u]++;
		fa[v]++;
	}
	for (int i = 1 ; i <= n ; i++){
		if (fa[i] == 1) {
			s = i;
			break;
		}
	}
	init(s , n);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d%d%d" , &x , &y , &z);
		int a1 = query(x , y);
		int a2 = query(x , z);
		int a3 = query(y , z);
		if (a1 == a2) {
			l = a3;
		}
		else if (a1 == a3) {
			l = a2;
		}
		else if (a2 == a3) {
			l = a1;
		}
		p = dep[x] + dep[y] + dep[z] - dep[a1] - dep[a2] - dep[a3];
		printf("%d %d\n" , l , p);
	}
}

#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1000005
struct Edge {
	int v , nx , w;
}e[MAXN];
int ecnt , head[MAXN] , xord[MAXN] , n , m , vis[MAXN] , u , v , w;
void add(int f , int t , int w) {
	e[++ecnt] = (Edge){t , head[f] , w};
	head[f] = ecnt;
}
void dfs(int p , int xorz) {
	vis[p] = 1;
	xord[p] = xorz;
	for (int i = head[p] ; i ; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to]) continue;
		dfs(to, xorz ^ e[i].w);
	}
}
int main() {
	scanf("%d" , &n);
	for (int i = 1 ; i < n ; i++) {
		scanf("%d%d%d" , &u , &v , &w);
		add(u , v , w);
		add(v , u , w);
	}
	dfs(1 , -1);
	scanf("%d" , &m);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d%d" , &u , &v);
		printf("%d\n" , xord[u] ^ xord[v]);
	}
}
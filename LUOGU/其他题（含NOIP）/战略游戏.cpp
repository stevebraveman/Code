#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 60005
struct Edge {
	int v , nx;
}e[MAXN];
int ecnt , head[MAXN] , n , m , fa[MAXN] , dp[MAXN][2] , t , k;
bool vis[MAXN];
inline int min(int a , int b) {
	if (a < b) return a;
	else return b;
}
inline int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
void add(int f , int t) {
	e[++ecnt] = (Edge){t , head[f]};
	head[f] = ecnt;
}
void dfs(int x , int y) {
	dp[x][1] = 1;
	dp[x][0] = 0;
	for (int i = head[x] ; i ; i = e[i].nx) {
		int go = e[i].v;
		if (go == y) continue;
		dfs(go , x);
		dp[x][0] += dp[go][1];
		dp[x][1] += min(dp[go][1] , dp[go][0]);
	}
}
int main() {
	scanf("%d" , &n);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , &m);
		scanf("%d" , &k);
		for (int j = 1 ; j <= k ; j++) {
			scanf("%d" , &t);
			add(m , t);
			add(t , m);
		}
	}
	dfs(0 , -1);
	printf("%d" , min(dp[0][1] , dp[0][0]));
}
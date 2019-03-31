#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1000005
struct Edge {
	int to , nx;
}e[MAXN * 4];
int ecnt , head[MAXN] , maxn[MAXN] , n , m;
void add(int from , int to) {
	e[++ecnt] = (Edge){to , head[from]};
	head[from] = ecnt;
}
void dfs(int n , int s) {
	if (maxn[n]) return;
	maxn[n] = s;
	for (int i = head[n] ; i ; i = e[i].nx) {
		if (!maxn[e[i].to]) dfs(e[i].to , s);
	}
	return;
}
int main() {
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= m ; i++) {
		int u , v;
		scanf("%d%d" , &u , &v);
		add(v , u);
	}
	for (int i = n ; i ; --i) {
		dfs(i , i);
	}
	for (int i = 1 ; i <= n ; i++) {
		printf("%d " , maxn[i]);
	}
}
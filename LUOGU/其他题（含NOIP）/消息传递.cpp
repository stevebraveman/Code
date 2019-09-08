#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10005
struct Edge {
	int v , nx;
}e[MAXN];
int head[MAXN] , ecnt , n , m , u , v , minn = 0x7fffffff , ans[MAXN];
void add(int f , int t) {
	e[++ecnt] = (Edge){t , head[f]};
	head[f] = ecnt;
}
inline int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
inline int min(int a , int b) {
	if (a < b) return a;
	else return b;
}
void dfs(int p , int f , int r) {
	ans[r]++;
	for (int i = head[p] ; i ; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs(to , p , r);
	}
}
int main() {
	freopen("data.in" , "r" , stdin);
	freopen("data.out" , "w" , stdout);
	scanf("%d" , &n);
	for (int i = 2 ; i <= n ; i++) {
		scanf("%d" , &u);
		add(u , i);
		add(i , u);
	}
	for (int i = 1 ; i <= n ; i++) {
		dfs(i , 0 , i);
	}
	for (int i = 1 ; i <= n ; i++) {
		minn = min(ans[i] , minn);
	}
	printf("%d\n" , minn);
	for (int i = 1 ; i <= n ; i++) {
		if (ans[i] == minn) {
			printf("%d " , i);
		}
	}
	fclose(stdin);
	fclose(stdout);
}
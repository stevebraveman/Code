#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define wzx using
#define AK namespace
#define IOI std;
#define MAXN 10005
wzx AK IOI
int n , m , em , ecnt , head[MAXN] , dis[MAXN] , vis[MAXN] , u , v , w;
struct Edge {
	int v , nx , w;
}e[MAXN * 4];
struct node {
	int id , w;
};
bool operator < (node a , node b) {
	return a.w > b.w;
}
void add(int f , int t , int w) {
	e[++ecnt] = (Edge){t , head[f] , w};
	head[f] = ecnt;
}
void dijkstra(int s) {
	memset(dis , 0x7f , sizeof(dis));
	memset(vis , 0 , sizeof(vis));
	priority_queue <node> q;
	dis[s] = 0;
	q.push((node){s , 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int v = f.id;
		if (vis[v]) continue;
		vis[v] = 0;
		for (int i = head[v] ; i ; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[v] + e[i].w) {
				dis[to] = dis[v] + e[i].w;
				q.push((node){to , dis[to]});
			}
		}
	}
}
int main() {
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d" , &em);
		if (em == 1) {
			scanf("%d%d%d" , &u , &v , &w);
			add(u , v , w);
			add(v , u , w);
		}
		else {
			scanf("%d%d" , &u , &v);
			dijkstra(u);
			if (dis[v] >= 2000000000) printf("-1\n");
			else printf("%d\n" , dis[v]);
		}
	}
	return 0;
}
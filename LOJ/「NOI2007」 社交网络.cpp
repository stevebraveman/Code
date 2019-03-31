#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000
struct Edge {
	int v , nx , w;
}e[MAXN];
int n , m , ecnt , dis[MAXN] , vis[MAXN] , head[MAXN] , x , y , z , s;
struct node {
	int id , d;
};
void add(int from , int to , int w) {
	e[++ecnt] = (Edge){to , head[from] , w};
	head[from] = ecnt;
}
bool operator < (node a , node b) {
	return a.d > b.d;
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
		vis[v] = 1;
		for (int i = head[v] ; i ; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[v] + e[i].w) {
				dis[to] = dis[v] + e[i].w;
				q.push((node){to , dis[to]});
			}
		}
	}
}
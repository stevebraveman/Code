#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 100000
#define INF 2147483647
struct Edge {
	int v , nx , w;
}e[MAXN * 4];
int min(int a , int b) {
	if (a < b) return a;
	else return b;
}
int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
int head[MAXN] , dist[MAXN] , n , m , ans = INF , ans2 = INF , ecnt , w , u , v , k , ki , x , y , dis1[MAXN] , dis2[MAXN];
bool vis[MAXN], cant[MAXN];
void add(int f , int t , int w) {
	e[++ecnt].v = t;
	e[ecnt].nx = head[f];
	e[ecnt].w = w;
	head[f] = ecnt;
}
struct node {
	int id , w;
};
bool operator < (node a , node b) {
	return a.w > b.w;
}
void dijkstra1(int s , int dis[]) {
	memset(vis , 0 , sizeof(vis));
	std::priority_queue <node> q;
	q.push((node){s , 0});
	dis[s] = 0;
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
void dijkstra2(int s , int dis[]) {
	memset(vis , 0 , sizeof(vis));
	std::priority_queue <node> q;
	q.push((node){s , 0});
	dis[s] = 0;
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int v = f.id;
		if (vis[v]) continue;
		vis[v] = 1;
		for (int i = head[v] ; i ; i = e[i].nx) {
			int to = e[i].v;
			if (cant[to] == 1) continue;
			if (dis[to] > dis[v] + e[i].w) {
				dis[to] = dis[v] + e[i].w;
				q.push((node){to , dis[to]});
			}
		}
	}
}
void init() {
	memset(dis1 , 0x7f , sizeof(dis1));
	memset(dis2 , 0x7f , sizeof(dis2));
	memset(dist , 0x7f , sizeof(dist));
}
int main() {
	memset(cant , 0 , sizeof(cant));
	init();
	scanf("%d%d%d" , &n , &m , &k);
	for (int i = 1 ; i <= k ; i++) {
		scanf("%d" , &ki);
		cant[ki] = 1;
	}
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d%d%d" , &u , &v , &w);
		add(u , v , w);
		add(v , u , w);
	}
	scanf("%d%d" , &x , &y);
	dijkstra1(x , dist);
	ans = min(dist[1] + dist[y] , ans);
	init();
	dijkstra1(y , dist);
	ans = min(ans , dist[1] + dist[x]);
	init();
	dijkstra1(1 , dis1);
	dijkstra2(1 , dis2);
	ans2 = max(dis1[x] , dis2[y]);
	ans2 = min(ans2 , max(dis1[y] , dis2[x]));
	printf("%d" , min(ans , ans2));
}

#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#define MAXN 100005
#define wzx using
#define AK namespace
#define IOI std;
wzx AK IOI
struct point {
	int x , y;
}p[MAXN];
struct Edge {
	int v , nx ;
	double w;
}e[MAXN * 4];
int n , m , ecnt , x , y , u , v , head[MAXN]; 
double dis1[MAXN] , dis2[MAXN];
bool vis[MAXN]; 
struct node {
	int id;
	double w;
};
bool operator < (node a , node b) {
	return a.w > b.w;
}
void add(int f , int t , double w) {
	e[++ecnt] = (Edge){t , head[f] , w};
	head[f] = ecnt;
}
double d(point a , point b) {
	return sqrt(((double)a.x - b.x) * ((double)a.x - b.x) + ((double)a.y - b.y) * ((double)a.y - b.y)); 
}
void init() {
	for (int i = 1 ; i <= n ; i++) {
		dis1[i] = 19260817.999999;
		dis2[i] = 19260817.999999;
	}
}
void dijkstra(int s , double dis[]) {
	memset(vis , 0 , sizeof(vis));
	dis[s] = 0.0;
	priority_queue <node> q;
	q.push((node){s , 0.0});
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
int mp[205][205];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		if (mp[u][v] == 1 || mp[v][u] == 1) continue;
		mp[u][v] = mp[v][u] = 0;
		add(u, v, d(p[u], p[v]));
		add(v, u, d(p[u], p[v]));
	}
	init();
	dijkstra(1, dis1);
	dijkstra(n, dis2);
	double INF = 222222222.000;
	double ans = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = head[i]; j; j = e[j].nx) {
			int v = e[j].v;
			double k = e[j].w;
			double tem = dis1[i] + dis2[v] + k;
			if (tem > dis1[n] && tem < ans) {
				ans = tem;
			}
		}
	}
	if (ans >= INF) {
		printf("-1");
		return 0;
	}
	printf("%.2f", ans);
	return 0;
}
/*
3 4
0 0
1 1
0 2
1 2
1 3
2 3
2 1
 */
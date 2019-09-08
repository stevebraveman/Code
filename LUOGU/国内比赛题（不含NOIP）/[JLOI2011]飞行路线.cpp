#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
int n , m , h , u , t , v , c , s , tot;
int dis[2000010] , head[2000010];
bool vis[2000010];
struct edge {
	int v , nx , w;
} e[20000010];
struct node {
	int id , d;
};
bool operator < (node a , node b) {
	return a.d > b.d;
}
void add(int f , int t , int c = 0) {
	e[++tot] = ((edge) {t , head[f] , c});
	head[f] = tot;
}
void dijkstra(int s) {
	memset(dis , 0x7f , sizeof(dis));
	memset(vis , 0 , sizeof(vis));
	dis[s] = 0;
	std::priority_queue <node> q;
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
int main() {
	memset(head , 0 , sizeof(head));
	scanf("%d%d%d" , &n , &m , &h);
	scanf("%d%d" , &s , &t);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d%d%d" , &u , &v , &c);
		add(u , v , c);
		add(v , u , c);
		for(int j = 1 ; j <= h ; j++) {
			add(u + (j - 1) * n , v + j * n);
			add(v + (j - 1) * n , u + j * n);
			add(u + j * n , v + j * n , c);
			add(v + j * n , u + j * n , c);
		}
	}
	for (int i = 1 ; i <= h ; i++) {
		add(t + (i - 1) * n , t + i * n);
	}
	dijkstra(s);
	printf("%d\n" , dis[t + h * n]);
	return 0;
}

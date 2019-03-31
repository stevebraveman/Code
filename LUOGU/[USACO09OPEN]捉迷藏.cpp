#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 100005
#define wzx using 
#define AK namespace 
#define IOI std;
wzx AK IOI
struct Edge {
	int v , nx , w;
}e[MAXN * 4];
struct node {
	int id , w;
};
bool operator < (node a , node b) {
	return a.w > b.w;
}
bool flag = 0;
int n , m , ecnt , head[MAXN] , dis[MAXN] , vis[MAXN] , u , v , w , ans = 0 , tot;
void add(int f , int t , int w) {
	e[++ecnt] = (Edge){t , head[f] , w};
	head[f] = ecnt;
}
inline int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
void dijkstra(int s) {
	memset(dis , 0x7f , sizeof(dis));
	memset(vis , 0 , sizeof(vis));
	dis[s] = 0;
	priority_queue <node> q;
	q.push((node){s , 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int v = f.id;
		if(vis[v]) continue;
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
	scanf("%d%d" , &n , &m);
	for (int i = 1; i <= m ; i++) {
		scanf("%d%d" , &u , &v);
		add(u , v , 1);
		add(v , u , 1);
	}
	dijkstra(1);
	for (int i = 1 ; i <= n ; i++) {
		ans = max(dis[i] , ans);
	}
	for (int i = 1 ; i <= n ; i++) {
		if (dis[i] == ans && flag == 0) {
			flag = 1;
			printf("%d " , i);
		}
		if (dis[i] == ans) {
			tot++;
		}
	}
	printf("%d %d" , ans , tot);
}
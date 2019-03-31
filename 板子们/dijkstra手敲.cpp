#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 5005
using namespace std;
int dis[MAXN] , vis[MAXN] , ecnt , n , m , u , head[MAXN];
struct Edge{
	int v , nx , w;
}e[MAXN * 4];
struct node{
	int id , w;
};
bool operator < (node a , node b) {
	return a.w > b.w;
}
void add(int from , int to , int weight) {
	e[++ecnt] = (Edge){to , head[from] , weight};
	head[from] = ecnt;
}
void dijkstra(int s) {
	memset(dis , 0x7f , sizeof (dis));
	memset(vis , 0 , sizeof (vis));
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
int main() {
	// freopen("data.in" , "r" , stdin);
	// freopen("data.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m , &u);
	for (int i = 1 ; i <= m ; i++) {
		int x , y , z;
		scanf("%d%d%d" , &x , &y , &z);
		add(x , y , z);
		add(y , x , z);
	}
	dijkstra(u);
	for (int i = 1 ; i <= n ; i++) {
		printf("%d " , dis[i]);
	}
}
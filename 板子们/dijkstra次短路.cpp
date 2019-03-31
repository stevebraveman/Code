#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define ll long long
#define R 100005
#define INF 2147483647
#define MOD 19260817
using namespace std;
struct Edge {
	int v;
	int w;
	int nx;
} e[R*2];
struct node {
	int id , w;
};
bool operator < (node a , node b) {
	return a.w > b.w;
}
int head[R] , dist1[R] , dist2[R] , num , n , m , dist3[R];
bool vis[R];
void init() {
	num = 0;
	memset(dist1 , 0x7f , sizeof(dist1));
	memset(dist2 , 0x7f , sizeof(dist2));
}
void add_edge(int u , int v , int w) {
	e[++num].v = v;
	e[num].w = w;
	e[num].nx = head[u];
	head[u] = num;
}
void dijkstra(int s , int dis[]) {
	memset(vis , 0 , sizeof (vis));
	priority_queue <node> q;
	dis[s] = 0;
	q.push((node) {s , 0});
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
				q.push((node) {to , dis[to]}); 
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	int u , v , w;
	init();
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d%d%d" , &u , &v , &w);
		add_edge(u , v , w);
		add_edge(v , u , w);
	}
	dijkstra(1 , dist1);
	dijkstra(n , dist2);
	int ans = INF;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = head[i] ; j ; j = e[j].nx) {
			v = e[j].v;
			w = e[j].w;
			int tem = dist1[i] + dist2[v] + w;
			if (tem > dist1[n] && tem < ans) {
				ans = tem;
			}
		}
	}
	dijkstra(1 , dist3);
	ll a = ((ll)dist3[n] * (ll)ans) % MOD;
	printf("%d\n" , a);
	return 0;
}
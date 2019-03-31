#include <cstdio>
#include <queue>
#include <cstring>
#define MOD 100003
#define MAXN 1000001
using namespace std;
int n , m , dis[MAXN] , vis[MAXN] , ecnt , head[MAXN] , s , ans[MAXN];
struct Edge {
	int to , nx ,w;
}e[MAXN * 4];
struct node {
	int id , w;
};
bool operator < (node a , node b) {
	return a.w > b.w;
}
void add(int from , int to , int weight) {
	e[++ecnt] = (Edge){to , head[from] , weight};
	head[from] = to;
}
int dijkstra(int s) {
	memset(dis , 0x7f , sizeof (dis));
	memset(vis , 0 , sizeof (vis));
	memset(ans , 0 , sizeof (ans));
	priority_queue <node> q;
	dis[s] = 0;
	ans[s] = 1;
	q.push((node){s , 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int v = f.id;
		if (vis[v]) continue;
		vis[v] = 1;
		for (int i = head[v] ; i ; i = e[i].nx) {
			int to = e[i].to;
			if (dis[to] > dis[v] + e[v].w) {
				dis[to] = dis[v] + e[v].w;
				ans[to] = ans[v];
				q.push((node){to , dis[to]});
			}
			else if (dis[to] = dis[v] + e[v].w) {
				ans[to] = (ans[to] + ans[v]) % MOD;
			}
		}
	}
}
int main() {
	scanf("%d%d%d" , &n , &m , &s);
	for (int i = 1 ; i <= m ; i++){
		int x , y , z;
		scanf("%d%d%d" , &x , &y , &z);
		add(x , y , z);
		add(y , x , z);
	}
	dijkstra(s);
	for (int i = 1 ; i <= n ; i++) {
		printf("%d " , ans[i] % MOD);
	}
	return 0;
}
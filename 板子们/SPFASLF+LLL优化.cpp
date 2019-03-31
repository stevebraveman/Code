/*
  其实这也就是一个普通的SPFA而已。。。。。。。
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn=300001;
const int inf=2147483647;
struct edge {
	int to , w , next;
} e[1000001];
int head[maxn] , vis[maxn] , dist[maxn] , n , m , t;
void add(int i , int j , int w) {
	e[++t].to = j;
	e[t].w = w;
	e[t].next = head[i];
	head[i] = t;
}
void spfa(int s) {
	queue <int> q;
	for(int i = 1 ; i <= n ; i++)
		dist[i] = inf;
	memset(vis , 0 , sizeof(vis));
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i ; i = e[i].next) {
			int v = e[i].to;
			if (dist[v] > dist[u] + e[i].w) {
				dist[v] = dist[u] + e[i].w;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
}
int main() {
	int a , b , c , s , e , maxdis=0 , u;
	scanf("%d%d%d" , &n , &m , &u);
	t = 0;
	memset(head , 0 , sizeof(head));
	while (m--) {
		scanf("%d%d%d" , &a , &b , &c);
		add(a , b , c);
	}
	spfa(u);
	for (int i = 1 ; i <= n ; i++) {
		printf("%d " , dist[i]);
	}
	return 0;
}
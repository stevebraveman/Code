#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200000
#define re register
inline void read(int &x) {
	x = 0;int f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1;c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0';c = getchar();}
	x = x * f;
}
struct Edge {
	int v , nx , w;
}e[MAXN];
int head[MAXN] , dis[MAXN] , ecnt = 0 , u , v , w , t , ans[MAXN] , vis[MAXN] , n , m;
inline void add(int f , int t , int w) {
	e[++ecnt] = (Edge) {t , head[f] , w};
	head[f] = ecnt;
}
inline bool spfa(int s) {
	memset(vis , 0 , sizeof(vis));
	memset(dis , 0x7f , sizeof(dis));
	dis[s] = 0;
	vis[s] = 1;
	std::queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vis[v] = 0;
		if (ans[v] >= n) return 1;
		for (re int i = head[v] ; i ; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[v] + e[i].w) {
				dis[to] = dis[v] + e[i].w;
				if (!vis[to]) {
					q.push(to);
					vis[to] = 1;
					ans[to]++;
					if (ans[to] >= n) return 1;
				}
			}
		}
	}
	return 0;
}
int main() {
	read(t);
	while (t--) {
		ecnt = 0;
		memset(head , 0 , sizeof(head));
		memset(ans , 0 , sizeof(ans));
		read(n);read(m);
		for (int i = 1 ; i <= m ; i++) {
			read(u);read(v);read(w);
			add(u , v , w);
			if (w >= 0)
			add(v , u , w);
		}
		if (spfa(1)) {
			printf("YE5\n");
		}
		else {
			printf("N0\n");
		}
	}
}
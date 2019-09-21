#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10000010
namespace STman {
	template <typename Tp>
	inline void read(Tp &x) {
		#define C getchar()
		Tp f = 1;x = 0;
		char k = C;
		while (k < '0' || k > '9') {if (k == '-') f = -1;k = C;}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0';k = C;}
		x = x * f;
		#undef C
	}
	template <typename Tp>
	inline void write(Tp x) {
		if (x < 0) putchar('-') , x = -x;
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
	template <typename Tp>
	inline Tp max(Tp a , Tp b) {
		if (a > b) return a;
		else return b;
	}
	template <typename Tp>
	inline Tp min(Tp a , Tp b) {
		if (a < b) return a;
		else return b;
	}
	template <typename Tp>
	inline void swap(Tp &a , Tp &b) {
		Tp t = a;
		a = b;
		b = t;
	}
	template <typename Tp>
	inline Tp abs(Tp &a) {
		if (a < 0) return -a;
		else return a;
	}
	inline void sp() {
		putchar(32);
	}
	inline void et() {
		putchar(10);
	}
}
using namespace STman;
struct Edge {
	int v , nx , w;
}e[MAXN];
int head[MAXN] , hd , dis[MAXN] , tim , st[MAXN] , x , y , w , n , m , ecnt;
int dfn[MAXN] , low[MAXN] , in[MAXN] , num;
bool vi[MAXN] , vis[MAXN];
void add1(int f , int t , int w) {
	e[++ecnt] = (Edge){t , head[f] , w};
	head[f] = ecnt;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++hd] = u;
	vi[u] = 1;
	for (int i = head[u] ; i ; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u] , low[v]);
		}
		if (vi[v]) low[u] = min(dfn[v] , low[u]);
	}
	if (dfn[u] == low[u]) {
		num++;
		int v;
		do {
			v = st[hd--];
			vi[v] = 0;
			in[v] = num;
		} while(v != u);
	}
}
void spfa(int s) {
	memset(dis , 0x7f , sizeof(dis));
	memset(vis , 0 , sizeof(vis));
	vis[s] = 1;
	dis[s] = 0;
	std::queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vis[v] = 0;
		for (int i = head[v] ; i ; i = e[i].nx) {
			int to = e[i].v;
			int w = in[to] == in[v] ? 0 : e[i].w;
			if (dis[to] > dis[v] + w) {
				dis[to] = dis[v] + w;
				if (!vis[to]) {
					q.push(to);
					vis[to] = 1;
				}
			}
		}
	}
}
int main() {
	read(n) , read(m);
	for (int i = 1 ; i <= m ; i++) {
		read(x) , read(y) , read(w);
		add1(x , y , w);
	}
	for (int i = 1 ; i <= n ; i++) {
		if (!dfn[i]) tarjan(i);
	}
	spfa(1);
	write(dis[n]);
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
#define INF 19260817
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
int head[MAXN] , dis[MAXN] , ecnt = 1 , n , k , x , y , maxn = -INF , g , d , ans = 0;
bool vis[MAXN] , l[MAXN];
void add(int f , int t , int w) {
	e[++ecnt] = (Edge) {t , head[f] , w};
	head[f] = ecnt;
}
void dfs(int p) {
	for (int i = head[p] ; i ; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to]) continue;
		vis[to] = 1;
		dis[to] = dis[p] + e[i].w;
		dfs(to);
	}
}
void dfs3(int p) {
	for (int i = head[p] ; i ; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to]) continue;
		vis[to] = 1;
		dfs3(to);
		if (l[to]) l[p] = 1 , e[i].w = -e[i].w , e[i ^ 1].w = -1;
	}
}
int main() {
	read(n) ,  read(k);
	ans += 2 * n - 2;
	for (int i = 1 ; i < n ; i++) {
		read(x) , read(y);
		add(x , y , 1);
		add(y , x , 1);
	}
	for (int i = 1 ; i <= k ; i++) {
		memset(l , 0 , sizeof(l));
		memset(vis , 0 , sizeof(vis));
		vis[1] = 1;
		dis[1] = 0;
		dfs(1);
		maxn = -INF;
		for (int j = 1 ; j <= n ; j++) {
			if (dis[j] > maxn) {
				g = j;
				maxn = dis[j];
			}
			write(maxn) , et();
		}
		memset(vis , 0 , sizeof(vis));
		maxn = -INF;
		dis[g] = 0;
		vis[g] = 1;
		dfs(g);
		et();
		for (int j = 1 ; j <= n ; j++) {
			if (dis[j] > maxn) {
				d = j;
				maxn = dis[j];
			}
			write(maxn) , et();
		}
		et();
		et();
		ans -= (maxn - 1);
		write(maxn) , et();
		if (k == 1) {
			break;
		}
		memset(vis , 0 , sizeof(vis));
		l[d] = 1;
		dfs3(g);
	}
	write(ans);
}
/*
8 2
1 2
3 1
3 4
5 3
7 5
8 5
5 6
 */
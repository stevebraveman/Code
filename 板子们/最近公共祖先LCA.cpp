#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 700000
#define LOG 30
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
	inline void swap(Tp &x , Tp &y) {
		Tp t = x;
		x = y;
		y = t;
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
	int v , nx;
}e[MAXN];
int head[MAXN] , ecnt , u , v , w , r , n , m , anc[MAXN][LOG] , dep[MAXN];
bool vis[MAXN];
void add(int f , int t) {
	e[++ecnt] = (Edge){t , head[f]};
	head[f] = ecnt;
}
void dfs(int p , int f) {
	for (int i = head[p] ; i ; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dep[to] = dep[p] + 1;
		anc[to][0] = p;
		dfs(to , p);
	}
}
void init(int p) {
	dep[p] = 1;
	dfs(p , 0);
	for (int i = 1 ; i < LOG ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			anc[j][i] = anc[anc[j][i - 1]][i - 1];
		}
	}
}
void swim(int &x , int h) {
	for (int i = 0 ; h > 0 ; i++) {
		if (h & 1) x = anc[x][i];
		h >>= 1;
	}
}
int LCA(int x , int y) {
	if (dep[x] < dep[y]) swap(x , y);
	swim(x , dep[x] - dep[y]);
	if (x == y) return x;
	for (int i = LOG - 1 ; i >= 0 ; i--) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0];
}
int main() {
	read(n) , read(m) , read(r);
	for (int i = 1 ; i < n ; i++) {
		read(u) , read(v);
		add(u , v);
		add(v , u);
	}
	init(r);
	for (int i = 1 ; i <= m ; i++) {
		read(u) , read(v);
		write(LCA(u , v)) , et();
	}
}
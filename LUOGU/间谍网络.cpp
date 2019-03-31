#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
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
int num , in[MAXN] , p[MAXN] , shm , x , y , size[MAXN] , sum[MAXN] , n , m;
int dfn[MAXN] , low[MAXN] , st[MAXN] , tim , hd , ecnt = 0 , ans , head[MAXN];
void add(int f , int t) {
	e[++ecnt] = (Edge) {t , head[f]};
	head[f] = ecnt;
}
bool vis[MAXN] , r[MAXN];
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++hd] = u;
	vis[u] = 1;
	for (int i = head[u] ; i ; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u] , low[v]);
		}
		else if (vis[v]) low[u] = min(dfn[v] , low[u]);
	}
	if (dfn[u] == low[u]) {
		num++;
		int v;
		do {
			v = st[hd--];
			vis[v] = 0;
			in[v] = num;
			sum[num] = min(sum[num] , p[v]);
		} while (v != u);
	}
}
int main() {
	read(n) , read(shm);
	for (int i = 1 ; i <= n ; i++) {
		p[i] = INF;
		sum[i] = INF;
	}
	for (int i = 1 ; i <= shm ; i++) {
		read(x) , read(y);
		p[x] = y;
	}
	read(m);
	for (int i = 1 ; i <= m ; i++) {
		read(x) , read(y);
		add(x , y);
	}
	for (int i = 1 ; i <= n ; i++) {
		if (!dfn[i] && p[i] != INF) {
			tarjan(i);
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		if (!dfn[i]) {
			puts("NO");
			write(i) , et();
			return 0;
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = head[i] ; j ; j = e[j].nx) {
			if (in[i] != in[e[j].v]) {
				r[in[e[j].v]] = 1;
			}
		}
	}
	puts("YES");
	for (int i = 1 ; i <= num ; i++) {
		if (!r[i]) {
			ans += sum[i];
		}
	}
	write(ans) , et();
}
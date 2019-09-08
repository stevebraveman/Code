#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAXN 1000002
#define INF 2000000000
namespace STman {
	inline char gc(){
		#ifdef ONLINE_JUDGE
			static char now[1 << 16], *S, *T;
			if (T == S) {T = (S = now) + fread(now, 1, 1 << 16, stdin); if (T == S) return EOF;}
			return *S++;
		#else 
			return getchar();
		#endif
	}
	template <typename Tp>
	inline void read(Tp &x) {
		Tp f = 1;x = 0;
		char k = gc();
		while (k < '0' || k > '9') {if (k == '-') f = -1;k = gc();}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0';k = gc();}
		x = x * f;
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
} e[MAXN];
std::queue <int> q;
int n , m , head[MAXN] , ecnt = 1  , x , y , z , r , k , dep[MAXN] , cur[MAXN];
void add(int f , int t , int w) {
	e[++ecnt] = (Edge) {t , head[f] , w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f , head[t] , 0};
	head[t] = ecnt;
}
bool bfs(int s , int t) {
	memset(dep , 0x7f , sizeof(dep));
	while (!q.empty()) q.pop();
	for (int i = 1 ; i <= n ; i++) {
		cur[i] = head[i];
	}
	dep[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = head[v] ; i ; i = e[i].nx) {
			int to = e[i].v;
			if (dep[to] > INF && e[i].w) {
				dep[to] = dep[v] + 1;
				q.push(to);
			}
		}
	}
	if (dep[t] < INF) return 1;
	else return 0;
}
int dfs(int u , int t , int l) {
	if (!l || u == t) {
		return l;
	}
	int fl = 0 , f;
	for (int i = cur[u] ; i ; i = e[i].nx) {
		cur[u] = i;
		int to = e[i].v;
		if (dep[to] == dep[u] + 1 && (f = dfs(to , t , min(l , e[i].w)))) {
			fl += f;
			l -= f;
			e[i ^ 1].w += f;
			e[i].w -= f;
			if (!l) break;
		}
	}
	return fl;
}
int Dinic(int s , int t) {
	int maxf = 0;
	while (bfs(s , t)) {
		maxf += dfs(s , t , INF);
	}
	return maxf;
}
int main() {
	read(n) , read(m) , read(r) , read(k);
	for (int i = 1 ; i <= m ; i++) {
		read(x) , read(y) , read(z);
		add(x , y , z);
	}
	write(Dinic(r , k));
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 100100
namespace STman {
	template <typename Tp>
	inline void read(Tp &x) {
		#define C getchar()
		Tp f = 1;x = 0;
		char k = C;
		while (k < '0' || k > '9') {if (k == '-') f = -1; k = C;}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0'; k = C;}
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
	inline Tp max(Tp a, Tp b) {
		if (a > b) return a;
		else return b;
	}
	template <typename Tp>
	inline Tp min(Tp a, Tp b) {
		if (a < b) return a;
		else return b;
	}
	template <typename Tp>
	inline void swap(Tp &a, Tp &b) {
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
	int v, w;
	Edge *nx;
}e[MAXN * 10], *head[MAXN * 10];
int ecnt, n, m, x, y, z, dis[MAXN], u;
bool vis[MAXN];
void add(int f, int t, int w) {
	Edge *p = &e[++ecnt];
	p -> v = t;
	p -> nx = head[f];
	p -> w = w;
	head[f] = p;
}
struct node {
	int id, w;
};
bool operator < (node a, node b) {
	return a.w > b.w;
}
void dijkstra(int s) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	dis[s] = 0;
	std::priority_queue <node> q;
	q.push((node){s, 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int u = f.id;
		if (vis[u]) continue;
		vis[u] = 1;
		for (Edge *p = head[u]; p; p = p -> nx) {
			int to = p -> v;
			if (dis[to] > dis[u] + p -> w) {
				dis[to] = dis[u] + p -> w;
				q.push((node){to, dis[to]});
			}
		}
	}
}
int main() {
	read(n), read(m), read(u);
	for (int i = 1; i <= m; i++) {
		read(x), read(y), read(z);
		add(x, y, z);
	}
	dijkstra(u);
	for (int i = 1; i <= n; i++) {
		write(dis[i]), sp();
	}
	return 0;
}
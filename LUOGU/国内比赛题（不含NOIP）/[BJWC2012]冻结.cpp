#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
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
int n, m, h, u, t, v, c, s, tot, ans = 0x7fffffff;
int dis[2000010], head[2000010];
bool vis[2000010];
struct edge {
	int v, nx, w;
} e[20000010];
struct node {
	int id, d;
};
bool operator < (node a, node b) {
	return a.d > b.d;
}
void add(int f, int t, int c) {
	e[++tot] = ((edge) {t , head[f] , c});
	head[f] = tot;
}
void dijkstra(int s) {
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	std::priority_queue <node> q;
	q.push((node){s, 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int v = f.id;
		if (vis[v]) continue;
		vis[v] = 1;
		for (int i = head[v]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[v] + e[i].w) {
				dis[to] = dis[v] + e[i].w;
				q.push((node){to, dis[to]});
			}
		}
	}
}
int main() {
	memset(head, 0, sizeof(head));
	read(n), read(m), read(h);
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(c);
		add(u, v, c);
		add(v, u, c);
		for(int j = 0; j <= h; j++) {
			add(u + j * n, v + j * n, c);
			add(v + j * n, u + j * n, c);
			if (j < h) {
				add(u + j * n, v + (j + 1) * n, c / 2);
				add(v + j * n, u + (j + 1) * n, c / 2);
			}
		}
	}
	dijkstra(1);
	for (int i = 1; i <= h + 1; i++) {
		ans = min(ans, dis[i * n]);
	}
	write(ans);
	return 0;
}

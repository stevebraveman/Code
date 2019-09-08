/**
 * 普通次短路
 */
/*
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int R=100000+5;
const int INF=0x7fffffff;
struct Edge {
	int v;
	int w;
	int nx;
} e[R*2];
struct node {
	int id, w;
};
bool operator < (node a, node b) {
	return a.w > b.w;
}
int head[R], dist1[R], dist2[R], num, n, m;
bool vis[R];
void init() {
	num = 0;
	memset(dist1, 0x7f, sizeof(dist1));
	memset(dist2, 0x7f, sizeof(dist2));
}
void add_edge(int u , int v , int w) {
	e[++num].v = v;
	e[num].w = w;
	e[num].nx = head[u];
	head[u] = num;
}
void dijkstra(int s , int dis[]) {
	memset(vis , 0 , sizeof (vis));
	priority_queue <node> q;
	dis[s] = 0;
	q.push((node) {s , 0});
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
				q.push((node) {to , dis[to]}); 
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	int u, v, w;
	init();
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	dijkstra(1, dist1);
	dijkstra(n, dist2);
	int ans = INF;
	for(int i = 1 ; i <= n ; i++) {
		for(int j = head[i]; j; j = e[j].nx) {
			v = e[j].v;
			w = e[j].w;
			int tem = dist1[i] + dist2[v] + w;
			if(tem > dist1[n] && tem < ans) {
				ans = tem;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
*/
/**
 * A*次短路
 */
#include <iostream>
#include <queue>
#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100015
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
	int v, nx, w;
}e1[MAXN * 10], e[MAXN * 10];
int ecnt, head1[MAXN], head[MAXN], f[MAXN], x, y, m, n, w, st, end, kth, ans[MAXN];
bool vis[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w}, head[f] = ecnt;
}
struct node {
	int id, w;
};
bool operator < (node a, node b) {
	return a.w > b.w;
}
void dijkstra(int s) {
	memset(f, 0x7f, sizeof(f));
	memset(vis, 0, sizeof(vis));
	f[s] = 0;
	std::priority_queue <node> q;
	q.push((node) {s, 0});
	while (!q.empty()) {
		node fi = q.top();
		q.pop();
		int v = fi.id;
		if (vis[v]) continue;
		vis[v] = 1;
		for (int i = head[v]; i; i = e[i].nx) {
			int to = e[i].v;
			if (f[to] > f[v] + e[i].w) {
				f[to] = f[v] + e[i].w;
				q.push((node) {to, f[to]});
			}
		}
	}
}
struct star {
	int id, f, g;
	bool operator < (const star &a) const {
		return a.f < f || (a.f == f && a.g < g);
	}
};
std::set<int> se;
int Astar(int s, int t, int k) {
	std::priority_queue <star> q;
	q.push((star) {s, f[s], 0});
	while (!q.empty()) {
		star fi = q.top();
		q.pop();
		int v = fi.id;
		int h = fi.g;
		if (v == t) se.insert(h);
		else ans[v]++;
		if (se.size() == k && v == t) {
			return fi.g;
		}
		if (se.size() > k && v == t) continue;
		if (ans[v] > k && v != t) continue;
		for (int i = head[v]; i; i = e[i].nx) {
			int to = e[i].v;
			q.push((star) {to, h + f[v] + e[i].w, h + e[i].w});
		}
	}
	return -1;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(x), read(y), read(w);
		add(x, y, w);
		add(y, x, w);
	}
	dijkstra(end);
	write(Astar(1, n, 2));
	return 0;
}
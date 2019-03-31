#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10015
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
	e1[ecnt] = (Edge) {f, head[t], w}, head1[t] = ecnt;
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
		for (int i = head1[v]; i; i = e1[i].nx) {
			int to = e1[i].v;
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
int Astar(int s, int t, int k) {
	if (s == t) k++;
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
	}
	read(st), read(end), read(kth);
	dijkstra(end);
	write(Astar(st, end, kth));
	return 0;
}
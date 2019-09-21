#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
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
bool vis[MAXN], vi[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w}, head[f] = ecnt;
	e1[ecnt] = (Edge) {f, head[t], w}, head1[t] = ecnt;
}
void spfa(int s) {
	memset(f, 0x7f, sizeof(f));
	memset(vis, 0, sizeof(vis));
	f[s] = 0;
	vis[s] = 0;
	std::queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vis[v] = 0;
		for (int i = head1[v]; i; i = e1[i].nx) {
			int to = e1[i].v;
			if (f[to] > f[v] + e[i].w) {
				f[to] = f[v] + e[i].w;
				if (!vis[to]) {
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
}
struct star {
	int id, f, g;
	std::vector<int> vec;
	bool operator < (const star &a) const {
		return a.f < f || (a.f == f && a.g < g) || (((a.f == f) && (a.g == g)) && a.vec < vec);
	}
};
void Astar(int s, int t, int k) {
	if (s == t) k++;
	std::priority_queue <star> q;
	star ll;
	ll.vec.push_back(s);
	ll.id = s, ll.f = f[s], ll.g = 0;
	q.push(ll);
	while (!q.empty()) {
		star fi = q.top();
		q.pop();
		int v = fi.id;
		int h = fi.g;
		ans[v]++;
		if (v == t && ans[v] == k) {
			for (int i = 0; i < (int)(fi.vec.size()); i++) {
				write(fi.vec[i]), putchar((i < fi.vec.size() - 1) ? '-' : '\n');
			}
			return;
		}
		for (int i = head[v]; i; i = e[i].nx) {
			int to = e[i].v;
			star cc;
			cc.id = to, cc.f = f[v] + h + e[i].w, cc.g = h + e[i].w;
			cc.vec.push_back(to);
			q.push(cc);
		}
	}
	puts("No");
}
int main() {
	read(n), read(m), read(kth), read(st), read(end);
	for (int i = 1; i <= m; i++) {
		read(x), read(y), read(w);
		add(x, y, w);
	}
	spfa(end);
	Astar(st, end, kth);
	return 0;
}
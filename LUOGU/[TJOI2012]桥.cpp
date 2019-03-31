#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdarg>
#include <queue>
#define full(a) memset(a, 0x7f, sizeof(a))
#define MAXN 1000010
template <typename _Tp>
void _read(_Tp &x) {
	x = 0;
	_Tp f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	x *= f;
}
template <typename _Tp>
void read(size_t n, _Tp* i...) {
	va_list args;
	va_start(args, i);
	_read(*i);
	while (--n) _read(*va_arg(args, _Tp*));
	va_end(args);
}
template <typename _Tp>
void _write(_Tp x) {
	if (x < 0) putchar(45);
	if (x > 9) _write(x / 10);
	putchar(x % 10 + '0');
}
template <typename _Tp>
void write(size_t n, _Tp i...) {
	va_list args;
	va_start(args, i);
	_write(i);
	while (--n) putchar(32), _write(va_arg(args, _Tp));
	va_end(args);
}
void sp() {
	putchar(32);
}

struct Edge {
	int v, nx, w;
}e[MAXN];
int head[MAXN], ecnt, n, m, dis1[MAXN], dis2[MAXN], x, y, z;
bool vis[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void fil() {
	full(dis1);
	full(dis2);
}
struct node {
	int id, w;
};
bool operator < (node a, node b) {
	return a.w > b.w;
}
void dijkstra(int s) {
	memset(vis, 0, sizeof(vis));
	priority_queue <node> q;
	q.push((node) {s, 0});
	dis1[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (vis[to]) continue;
		vis[to] = 1
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis1[to] > dis1[u] + e[i].w) {
				dis1[to] = dis1[u] + e[i].w;
				q.push((node) {})
			}
		}
	}
}
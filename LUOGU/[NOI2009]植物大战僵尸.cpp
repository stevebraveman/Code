#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdarg>
#include <queue>
#define MAXN 1000100
#define INF 2000000000
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
}e[MAXN << 2];
int head[MAXN], ecnt = 1, n, m, x, y, dep[MAXN], cur[MAXN], r, k, sc, at;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	dep[s] = 0;
	std::queue <int> q;
	for (int i = 1; i <= n * m + 2; i++) {
		cur[i] = head[i];
	}
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dep[to] > INF && e[i].w) {
				dep[to] = dep[u] + 1;
				q.push(to);
			}
		}
	}
	return dep[t] < INF;
}
int dfs(int s, int t, int l) {
	if (!l || s == t) {
		return l;
	}
	int fl = 0, f;
	for (int i = cur[s]; i; i = e[i].nx) {
		cur[s] = i;
		int to = e[i].nx;
		if (dep[to] == dep[s] + 1 && (f = dfs(to, t, min(l, e[i].w)))) {
			fl += f;
			l -= f;
			e[i].w -= f;
			e[i ^ 1].w += f;
			if (!l) break;
		}
	}
	return fl;
}
int Dinic(int s, int t) {
	int maxf = 0;
	while (bfs(s, t)) {
		maxf += dfs(s, t, INF);
	}
	return maxf;
}
int g(int i, int j) {
	return (i - 1) * m + j;
}
int main() {
	read(2, &n, &m);
	r = n * m + 1;
	k = r + 1;
	for (int i = 1; i <= n * m; i++) {
		read(2, &sc, &at);
		if (sc > 0) {
			add(r, i, sc);
		}
		else {
			add(i, k, -sc);
		}
		for (int I = 1; I <= at; I++) {
			read(2, &x, &y);
			x++;
			y++;
			add(i, g(x, y), INF);
		}
	}
	write(1, Dinic(r, k));
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 2000000000
#define MAXN 1000000
inline int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, w;
}e[MAXN];
int head[MAXN], ecnt = 1, n, m, x, y, cur[MAXN], dep[MAXN], r, k, tot, opt;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
std::queue <int> q;
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	while (!q.empty()) q.pop();
	for (int i = 1; i <= opt; i++) {
		cur[i] = head[i];
	}
	dep[s] = 0;
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
	if (dep[t] > INF) return 0;
	else return 1;
}
int dfs(int s, int t, int l) {
	if (!l || s == t) return l;
	int fl = 0, f;
	for (int i = cur[s]; i; i = e[i].nx) {
		int to = e[i].v;
		cur[s] = i;
		if (dep[to] == dep[s] + 1 && (f = dfs(to, t, min(e[i].w, l)))) {
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
	scanf("%d%d", &n, &m);
	r = n * m + 1;
	k = r + 1;
	opt = k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &x);
			tot += x;
			add(r, g(i, j), x);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &x);
			tot += x;
			add(g(i, j), k, x);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &x);
			tot += x;opt++;
			add(r, opt, x);
			add(opt, g(i, j), INF);
			if (i > 1) {
				add(opt, g(i - 1, j), INF);
			}
			if (i < n) {
				add(opt, g(i + 1, j), INF);
			}
			if (j > 1) {
				add(opt, g(i, j - 1), INF);
			}
			if (j < m) {
				add(opt, g(i, j + 1), INF);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &x);
			tot += x;
			opt++;
			add(opt, k, x);
			add(g(i, j), opt, INF);
			if (i > 1) {
				add(g(i - 1, j), opt, INF);
			}
			if (i < n) {
				add(g(i + 1, j), opt, INF);
			}
			if (j > 1) {
				add(g(i, j - 1), opt, INF);
			}
			if (j < m) {
				add(g(i, j + 1), opt, INF);
			}
		}
	}
	printf("%d\n", tot - Dinic(r, k));
	return 0;
}
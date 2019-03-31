#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 100010
struct Edge {
	int v, nx;
	bool vis;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, opt, p[MAXN], maxx, dep[MAXN], tot, f[MAXN], in[MAXN];
bool vi[MAXN];
int max(int a, int b) {
	if (a > b) return a;
	return b;
}
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f], 0};
	head[f] = ecnt;
}
void bfs(int s) {
	std::queue <int> q;
	q.push(s);
	dep[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			if (e[i].vis) continue;
			e[i].vis = 1;
			int to = e[i].v;
			if (dep[to] < n) dep[to] = dep[u] + 1;
			q.push(to);
		}
	}
}
int toposort(int x) {
	std::queue <int> q;
	q.push(x);
	f[x] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			if (!e[i].vis) continue;
			e[i].vis = 0;
			int to = e[i].v;
			f[to] += f[u];
			in[to]--;
			if (in[to] == 0) q.push(to);
		}
	}
	return f[maxx];
}
int main() {
	scanf("%d", &opt);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			add(i, i % p[j]);
			in[i % p[j]]++;
		}
	}
	bfs(m);
	for (int i = 1; i <= m; i++) {
		if (dep[i] == n) maxx = max(maxx, i);
	}
	printf("%d\n", maxx);
	memset(dep, 0, sizeof(dep));
	if (opt == 0) {
		return 0;
	}
	printf("%d", toposort(m));
	return 0;
}
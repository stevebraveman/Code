#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 50100
#define MOD 10000 
struct Edge {
	int v, nx, w;
}e[MAXN];
int head[MAXN], ecnt, n, m, x, y, z, s, t, t0;
int f[MAXN], dis[MAXN], in[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void toposort(int s) {
	std::queue <int> q;
	q.push(s);
	f[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			f[to] += f[u];
			f[to] %= MOD;
			dis[to] += dis[u] + e[i].w * f[u];
			dis[to] %= MOD;
		}
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			in[to]--;
			if (!in[to]) q.push(to);
		}
	}
}
int main() {
	scanf("%d%d%d%d%d", &n, &m, &s, &t, &t0);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		if (x != y) add(y, x, z), in[x]++;
	}
	toposort(t);
	printf("%d", (dis[s] % MOD + (f[s] - 1) % MOD * t0) % MOD);
}
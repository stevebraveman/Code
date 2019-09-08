#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#define MAXN 500100
#define INF 0x7fffffff
struct Edge {
	int v, nx, w, c;
}e[MAXN << 1];
int head[MAXN], r, k, ecnt = 1, m, n, x, y, dis[MAXN], maxf, minc, flow[MAXN], la[MAXN], pre[MAXN], tot;
bool vis[MAXN];
void add(int f, int t, int w, int c) {
	e[++ecnt] = (Edge) {t, head[f], w, c};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, -c};
	head[t] = ecnt;
}
bool spfa(int s, int t) {
	for (int i = 1; i <= k; i++) {
		vis[i] = 0;
		dis[i] = 0x3f3f3f3f;
	}
	std::queue <int> q;
	dis[s] = 0;
	vis[s] = 1;
	flow[s] = 0x7fffffff;
	q.push(s);
	pre[t] = -1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[u] + e[i].c && e[i].w) {
				dis[to] = dis[u] + e[i].c;
				flow[to] = std::min(e[i].w, flow[u]);
				la[to] = i;
				pre[to] = u;
				if (!vis[to]) {
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
	return pre[t] != -1;
}
void mcmf(int s, int t) {
	while (spfa(s, t)) {
		minc += dis[t] * flow[t];
		maxf += flow[t];
		int k = t;
		while (k) {
			int l = la[k];
			e[l].w -= flow[t];
			e[l ^ 1].w += flow[t];
			k = pre[k];
		}
		// printf("%d %d\n", maxf, minc);
	}
}
int main() {
	scanf("%d", &n);
	r = 2 * n + 1;
	k = r + 1;
	for (int i = 1; i <= n; i++) {
		add(r, i, 1, 0);
	}
	for (int i = 1; i <= n; i++) {
		add(i + n, k, 1, 0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x);
			tot += x;
			add(i, j + n, 1, -x);
		}
	}
	mcmf(r, k);
	printf("%d", tot + minc);
	return 0;
}
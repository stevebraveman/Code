#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000010
struct Edge {
	int v, nx, w, c;
}e[MAXN << 2];
int head[MAXN], b[MAXN], ecnt = 1, n, m, x, y, z;
int pre[MAXN], maxf, minc, dis[MAXN], la[MAXN], flow[MAXN], r, k, tot;
bool vis[MAXN];
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
void add(int f, int t, int w, int c) {
	e[++ecnt] = (Edge) {t, head[f], w, c};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, -c};
	head[t] = ecnt;
}
bool spfa(int s, int t) {
	memset(dis, 0x7f, sizeof(dis));
	memset(flow, 0x7f, sizeof(flow));
	memset(vis, 0, sizeof(vis));
	pre[t] = -1;
	dis[s] = 0;
	vis[s] = 1;
	std::queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vis[v] = 0;
		for (int i = head[v]; i; i = e[i].nx) {
			int f = e[i].w;
			int to = e[i].v;
			if (f > 0 && dis[to] > dis[v] + e[i].c) {
				dis[to] = dis[v] + e[i].c;
				pre[to] = v;
				la[to] = i;
				flow[to] = min(flow[v], f);
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
		int v = t;
		maxf += flow[t];
		minc += flow[t] * dis[t];
		while (v != s) {
			int k = la[v];
			e[k].w -= flow[t];
			e[k ^ 1].w += flow[t];
			v = pre[v];
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	r = 2 * n + 1;
	k = r + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		// b[i] = x;
		add(i + n, k, 1, 0);
		add(r, i, 1, 0);
		add(r, i + n, 1, x);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		if (x > y) std::swap(x, y);
		add(x, y + n, 1, z);
	}
	mcmf(r, k);
	printf("%d", minc);
	return 0;
}
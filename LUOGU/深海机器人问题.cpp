#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 100010
#define INF 2000000000
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, fl, w;
}e[MAXN];
int n, m, head[MAXN], dis[MAXN], ecnt = 1, flow[MAXN], maxf, minc, la[MAXN], pre[MAXN], x, y, z, f, ss = 0, tt = 10000;
bool vis[MAXN];
std::queue <int> q;
void add(int f, int t, int fl, int w) {
	e[++ecnt] = (Edge) {t, head[f], fl, w}, head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, -w}, head[t] = ecnt;
}
bool spfa(int s, int t) {
	memset(dis, 0x7f, sizeof(dis));
	memset(flow, 0x7f, sizeof(flow));
	memset(vis, 0, sizeof(vis));
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	pre[t] = -1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vis[v] = 0;
		for (int i = head[v]; i; i = e[i].nx) {
			int f = e[i].fl;
			int to = e[i].v;
			if (f > 0 && dis[to] > dis[v] + e[i].w) {
				dis[to] = dis[v] + e[i].w;
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
		minc += flow[t] * dis[t];
		while (v != s) {
			int k = la[v];
			e[k].fl -= flow[t];
			e[k ^ 1].fl += flow[t];
			v = pre[v];
		}
	}
}
int s, t, gg, hh, u, v, r;
int g(int i, int j) {
	return (i - 1) * t + j;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	s++, t++;
	for (int i = 1; i <= s; i++) {
		for (int j = 1; j < t; j++) {
			scanf("%d", &x);
			gg = g(i, j);
			add(gg, gg + 1, 1, -x);
			add(gg, gg + 1, INF, 0);
		}
	}
	for (int j = 1; j <= t; j++) {
		for (int i = 1; i < s; i++) {
			scanf("%d", &x);
			gg = g(i, j);
			add(gg, gg + t, 1, -x);
			add(gg, gg + t, INF, 0);
		}
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &r, &u, &v);
		u++, v++;
		add(ss, g(u, v), r, 0);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &r, &u, &v);
		u++, v++;
		add(g(u, v), tt, r, 0);
	}
	mcmf(ss, tt);
	printf("%d", -minc);
	return 0;
}
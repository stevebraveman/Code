#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 100010
#define INF 2000000000
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, fl, w;
}e[MAXN];
int n, m, head[MAXN], dis[MAXN], ecnt = 1, flow[MAXN], maxf, minc, la[MAXN], pre[MAXN], x, y, z, f, r, k;
int a[MAXN], b[MAXN], G[110][110];
bool vis[MAXN];
std::queue <int> q;
void add(int f, int t, int fl, int w) {
	e[++ecnt] = (Edge) {t, head[f], fl, w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, -w};
	head[t] = ecnt;
}
bool spfa(int s, int t) {
	memset(dis, 0x7f, sizeof(dis));
	memset(flow, 0x7f, sizeof(flow));
	memset(vis, 0, sizeof(vis));
	pre[t] = -1;
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
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
	maxf = 0;
	minc = 0;
	while (spfa(s, t)) {
		int v = t;
		maxf += flow[t];
		minc += flow[t] * dis[t];
		while (v != s) {
			int k = la[v];
			e[k].fl -= flow[t];
			e[k ^ 1].fl += flow[t];
			v = pre[v];
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	r = n + m + 1;
	k = r + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		add(r, i, a[i], 0);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		add(i + n, k, b[i], 0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &G[i][j]);
			add(i, j + n, INF, G[i][j]);
		}
	}
	mcmf(r, k);
	printf("%d\n", minc);
	memset(head, 0, sizeof(head));
	memset(e, 0, sizeof(e));
	ecnt = 1;
	for (int i = 1; i <= n; i++) {
		add(r, i, a[i], 0);
	}
	for (int i = 1; i <= m; i++) {
		add(i + n, k, b[i], 0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			add(i, j + n, INF, -G[i][j]);
		}
	}
	mcmf(r, k);
	printf("%d", -minc);
	return 0;
}
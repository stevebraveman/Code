#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define MAXN 100010
struct Edge {
	int v, nx, fl;
	long double w;
}e[MAXN];
int n, m, s, t, head[MAXN], ecnt = 1, flow[MAXN], maxf, la[MAXN], pre[MAXN], x, y, z, f;
long double dis[MAXN], minc, k;
bool vis[MAXN];
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
std::queue <int> q;
void add(int f, int t, int fl, long double w) {
	e[++ecnt] = (Edge) {t, head[f], fl, w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, -w};
	head[t] = ecnt;
}
bool spfa(int s, int t) {
	for (int i = 1; i <= 2 * n + 2; i++) {
		dis[i] = 9999999.9;
	}
	memset(flow, 0x7f, sizeof(flow));
	memset(vis, 0, sizeof(vis));
	q.push(s);
	dis[s] = 0.0;
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
		minc += (long double)flow[t] * dis[t];
		while (v != s) {
			int k = la[v];
			e[k].fl -= flow[t];
			e[k ^ 1].fl += flow[t];
			v = pre[v];
		}
	}
}
int main() {
	scanf("%d", &n);
	s = 2 * n + 1;
	t = s + 1;
	for (int i = 1; i <= n; i++) {
		add(s, i, 1, 0.0);
		add(i + n, t, 1, 0.0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x);
			k = (long double)x / 100.0;
			k = log2(k);
			add(i, j + n, 1, -k);
		}
	}
	mcmf(s, t);
	if (minc == 0.00) {
		printf("0.00000000\n");
		return 0;
	}
	printf("%.6f\n", pow(2, -minc) * 100.0);
	return 0;
}
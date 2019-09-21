#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#define MAXN 1101000
struct Edge {
	int v, nx, fl, w;
}e[MAXN << 2];
int n, m, head[MAXN], dis[MAXN], ecnt = 1, flow[MAXN], maxf, minc, la[MAXN], pre[MAXN], x, y, z, f, r, k;
bool vis[MAXN];
std::queue <int> q;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void add(int f, int t, int fl, int w) {
	e[++ecnt] = (Edge) {t, head[f], fl, w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, -w};
	head[t] = ecnt;
}
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
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
	while (spfa(s, t)) {
		// printf("%d\n", flow[t]);
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
bool check(int x, int y) {
	if (x < y) std::swap(x, y);
	int z = x * x - y * y;
	int p = sqrt(z);
	if (p * p != z) return 0;
	if (gcd(p, y) != 1) return 0;
	return 1;
}
int main() {
	scanf("%d%d", &n, &m);
	r = 100000;
	k = r + 1;
	for (int i = n; i < m; i++) {
		for (int j = i + 1; j <= m; j++) {
			if (check(i, j)) {
				add(i, j + 5000, 1, -(i + j));
				add(j, i + 5000, 1, -(i + j));
			}
		}
	}
	for (int i = n; i <= m; i++) {
		add(r, i, 1, 0);
		add(i + 5000, k, 1, 0);
	}
	mcmf(r, k);
	printf("%d %d", maxf / 2, -minc / 2);
}
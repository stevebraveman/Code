#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000100
#define INF 2000000000
struct Edge {
	int v, nx, w, c;
}e[MAXN << 1];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int head[MAXN], r, k, ecnt, n, m, pre[MAXN], x, y, z, flow[MAXN], dis[MAXN], la[MAXN], maxf, minc;
bool vis[MAXN];
void add(int f, int t, int w, int c) {
	e[++ecnt] = (Edge) {t, head[f], w, c};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, -c};
	head[t] = ecnt;
}
bool spfa(int s, int t) {
	for (int i = 1; i <= k; i++) {
		dis[k] = 0x7f7f7f7f;
		vis[i] = 0;
		flow[i] = 0x7f7f7f7f; 
	}
	std::queue <int> q;
	pre[t] = -1;
	q.push(s);
	vis[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[u] + e[i].c && e[i].w) {
				dis[to] = dis[u] + e[i].c;
				pre[to] = u;
				la[to] = i;
				flow[to] = min(flow[u], e[i].w);
				if (!vis[to]) {
					q.push(to);
					vis[to] = 1;
				}
			}
		}
	}
	return pre[t] != -1;
}
int a[MAXN], b[MAXN], c[MAXN];
int p[MAXN], tot;
bool chk[MAXN];
void seive(int n) {
	for (int i = 2; i <= n; i++) {
		if (!chk[i]) {
			p[++tot] = i;
		}
		for (int j = 1; j <= tot && i * p[j] <= n; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j] == 0) {
				break;
			}
		}
	}
}
bool prime(int x) {
	for (int i = 1; p[i] * p[i] <= x; i++) {
		if (x % p[i] == 0) return 0;
	}
	return 1;
}
void mcmf(int s, int t) {
	while (spfa(s, t)) {

	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (a[i] % a[j] == 0) {
				if (prime(a[i] / a[j])) {

				}
			}
		}
	}
}
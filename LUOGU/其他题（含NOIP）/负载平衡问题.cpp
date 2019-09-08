#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 100010
#define INF 2000000000
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, w, co;
}e[MAXN];
int head[MAXN], dis[MAXN], ecnt = 1, fl[MAXN], maxf, minc, la[MAXN], pre[MAXN], x, y, z, f, ans, r, k, n;
bool vis[MAXN];
void add(int f, int t, int fl, int c) {
	e[++ecnt] = (Edge) {t, head[f], fl, c};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, -c};
	head[t] = ecnt;
}
std::queue <int> q;
bool spfa(int s, int t) {
	memset(dis, 0x7f, sizeof(dis));
	memset(fl, 0x7f, sizeof(fl));
	memset(vis, 0, sizeof(vis));
	pre[t] = -1;
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (e[i].w > 0 && dis[to] > dis[u] + e[i].co) {
				dis[to] = dis[u] + e[i].co;
				pre[to] = u;
				la[to] = i;
				fl[to] = min(fl[u], e[i].w);
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
		maxf += fl[t];
		minc += fl[t] * dis[t];
		while (v != s) {
			int k = la[v];
			e[k].w -= fl[t];
			e[k ^ 1].w += fl[t];
			v = pre[v];
		}
	}
}
int a[MAXN];
int main() {
	scanf("%d", &n);
	r = n * 2 + 1;
	k = r + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ans += a[i];
	}
	ans = ans / n;
	for (int i = 1; i <= n; i++) {
		if (a[i] > ans) {
			add(r, i, a[i] - ans, 0);
		}
		else {
			add(i + n, k, ans - a[i], 0);
		}
		if (i - 1 > 0) {
			add(i, i - 1 + n, INF, 1);
			add(i, i - 1, INF, 1);
		}
		if (i + 1 <= n) {
			add(i, i + 1 + n, INF, 1);
			add(i, i + 1, INF, 1);
		}
	}
	add(1, n * 2, INF, 1);
	add(1, n, INF, 1);
	add(n, 1, INF, 1);
	add(n, 1 + n, INF, 1);
	mcmf(r, k);
	printf("%d", minc);
}
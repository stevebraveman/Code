#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#define MAXN 1000100
#define INF 2000000000000000LL
#define int long long
struct Edge {
	int v, nx, w, c;
}e[MAXN << 1];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int head[MAXN], r, k, ecnt = 1, n, m, pre[MAXN], x, y, z, flow[MAXN], dis[MAXN], la[MAXN], maxf, minc, ap[MAXN];
bool vis[MAXN];
void add(int f, int t, int w, int c) {
	e[++ecnt] = (Edge) {t, head[f], w, c};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, -c};
	head[t] = ecnt;
}
bool spfa(int s, int t) {
	for (int i = 1; i <= 2 * n; i++) {
		dis[i] = -0x7f7f7f7f7f7f7f7f;
		vis[i] = 0;
	}
	flow[s] = 0x7fffffffffffffff;
	std::queue <int> q;
	pre[t] = -1;
	q.push(s);
	vis[s] = 1;
	dis[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		// printf("%lld: ", u);
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			// printf("%lld ", to);
			if (dis[to] < dis[u] + e[i].c && e[i].w) {
				dis[to] = dis[u] + e[i].c;
				pre[to] = u;
				la[to] = i;
				flow[to] = std::min(flow[u], e[i].w);
				if (!vis[to]) {
					q.push(to);
					vis[to] = 1;
				}
			}
		}
		// puts("");
	}
	return pre[t] != -1;
}
int a[MAXN], b[MAXN], c[MAXN];
int div(int x) {
	int t = 0;
	for (int i = 2; i <= sqrt(x); i++) {
		while (x % i == 0) {
			x /= i;
			t++;
		}
	}
	return t + (x > 1);
}
void mcmf(int s, int t) {
	while (spfa(s, t)) {
		// printf("%lld\n", flow[t] * dis[t]);
		if (minc + flow[t] * dis[t] < 0) {
			maxf = maxf - minc / dis[t];
			return;
		}
		maxf += flow[t];
		minc += flow[t] * dis[t];
		int k = t;
		while (k != s) {
			int g = la[k];
			e[g].w -= flow[t];
			e[g ^ 1].w += flow[t];
			k = pre[k];
		}
	}
}
signed main() {
	scanf("%lld", &n);
	r = n + 1;
	k = r + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		ap[i] = div(a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &b[i]);
		if (ap[i] & 1) {
			add(r, i, b[i], 0);
			// printf("%lld -- %lld -> %lld\n", r, b[i], i);
		}
		else {
			add(i, k, b[i], 0);
			// printf("%lld -- %lld -> %lld\n", i, b[i], k);
		}
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (ap[i] & 1) {
			for (int j = 1; j <= n; j++) {
				if ((ap[i] == ap[j] + 1 && a[i] % a[j] == 0) || (ap[j] == ap[i] + 1 && a[j] % a[i] == 0)) {
					// printf("%lld -- %lld -> %lld\n", i, c[i] * c[j], j);
					add(i, j, INF, c[i] * c[j]);
				}
			}
		}
	}
	mcmf(r, k);
	printf("%lld", maxf);
}
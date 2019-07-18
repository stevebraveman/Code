#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 300010
#define clr(x) memset((x), 0, sizeof(x))
#define int long long
#define INF 0x7fffffffffffffffLL
struct Edge {
	int v, nx, w, id;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, _x, _y, _z, x[MAXN], y[MAXN], z[MAXN], p[MAXN];
int du[MAXN][2], k, T, dis[MAXN][2], s, t, ans;
bool vis[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w, 0};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], w, 1};
	head[t] = ecnt;
}
struct node {
	int id, w;
};
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
bool operator < (node a, node b) {
	return a.w > b.w;
}
void dijkstra(int op) {
	memset(vis, 0, sizeof(vis));
	std::priority_queue <node> q;
	for (int i = 1; i <= k; i++) {
		dis[p[i]][op] = 0;
		du[p[i]][op] = p[i];
		q.push((node) {p[i], 0});
	}
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int u = f.id;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nx) {
			if (op ^ e[i].id) continue;
			int to = e[i].v;
			if (dis[to][op] > dis[u][op] + e[i].w) {
				dis[to][op] = dis[u][op] + e[i].w;
				q.push((node) {to, dis[to][op]});
				du[to][op] = du[u][op];
			}
		}
	}
}
signed main() {
	scanf("%lld", &T);
	while (T--) {
		clr(head), clr(p), clr(e), clr(du);
		ecnt = 0;
		ans = INF;
		scanf("%lld%lld%lld", &n, &m, &k);
		for (int i = 1; i <= m; i++) {
			scanf("%lld%lld%lld", &_x, &_y, &_z);
			x[i] = _x;
			y[i] = _y;
			z[i] = _z;
			add(_x, _y, _z);
		}
		for (int i = 1; i <= k; i++) {
			scanf("%lld", &p[i]);
		}
		memset(dis, 0x7f, sizeof(dis));
		dijkstra(0);
		dijkstra(1);
		for (int i = 1; i <= m; i++) {
			if (du[x[i]][0] == du[y[i]][1]) continue;
			ans = min(ans, dis[x[i]][0] + dis[y[i]][1] + z[i]);
		}
		printf("%lld\n", ans);
	}
}
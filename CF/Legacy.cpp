
#i#include <iostream>nclude <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000100
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, s, l, r, rta;
int v[MAXN << 3], rk[MAXN];
int z, rtb, cnt;
int tot, ls[MAXN << 3], rs[MAXN << 3], opt, dis[MAXN];
bool vis[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void build(int l, int r, int &p, bool fl) {
	p = ++tot;
	if (l == r) {
		if (fl) v[l] = p;
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, ls[p], fl);
	build(m + 1, r, rs[p], fl);
	if (fl) add(ls[p], p, 0), add(rs[p], p, 0);
	else add(p, ls[p], 0), add(p, rs[p], 0);
}
void deal(int l, int r, int x, int y) {
	if (l == r) {
		add(y, x, 0);
		return;
	}
	int m = (l + r) >> 1;
	deal(l , m , ls[x] , ls[y]);
	deal(m + 1 , r , rs[x] , rs[y]);
}
void update(int x, int y, int l, int r, int p, int k, bool fl, int w) {
	if (x <= l && y >= r) {
		if (fl) add(p, k, w);
		else add(k, p, w);
		return;
	}
	int m = (l + r) >> 1;
	if (x <= m) update(x, y, l, m, ls[p], k, fl, w);
	if (y > m) update(x, y, m + 1, r, rs[p], k, fl, w);
}
void link(int x1, int y1, int pos, int k) {
	update(x1, y1, 1, n, rta, pos, 1, k);
	// add(tot, pos, k);
}
void link2(int x1, int y1, int pos, int k) {
	update(x1, y1, 1, n, rtb, pos, 0, k);
	// add(pos, tot, k);
}
struct node {
	int id, w;
};
bool operator < (node a, node b) {
	return a.w > b.w;
}
void dijkstra(int s) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	dis[s] = 0;
	std::priority_queue <node> q;
	q.push((node) {s, 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int u = f.id;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[u] + e[i].w) {
				dis[to] = dis[u] + e[i].w;
				q.push((node) {to, dis[to]});
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	build(1, n, rta, 1);
	build(1, n, rtb, 0);
	deal(1, n, rta, rtb);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &opt);
		switch(opt) {
			case 1: {
				scanf("%d%d%d", &x, &y, &z);
				add(x, y, z);
				break;
			}
			case 2: {
				scanf("%d%d%d%d", &x, &y, &z, &l);
				link2(y, z, x, l);
			}
			case 3: {
				scanf("%d%d%d%d", &x, &y, &z, &l);
				link(y, z, x, l);
			}
		}
	}
	dijkstra(v[s]);
	for (int i = 1; i <= n; i++) {
		printf("%d ", dis[v[i]]);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 101000
struct Edge {
	int v, nx, w;
}e[MAXN << 4];
int head[MAXN], ecnt, n, m, x, y, s, l, r, rta, f[MAXN];
int fa[MAXN], son[MAXN], size[MAXN], v[MAXN << 3], rk[MAXN];
int id[MAXN], top[MAXN], dep[MAXN], z, rtb, cnt;
int tot, ls[MAXN << 3], rs[MAXN << 3], opt, dis[MAXN];
int op[MAXN * 10][7], totp;
bool vis[MAXN];
int find(int x) {
	if (x == f[x]) return x;
	else return f[x] = find(f[x]);
}
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
void update(int x, int y, int l, int r, int p, int k, bool fl) {
	if (x <= l && y >= r) {
		if (fl) add(p, k, 0);
		else add(k, p, 0);
		return;
	}
	int m = (l + r) >> 1;
	if (x <= m) update(x, y, l, m, ls[p], k, fl);
	if (y > m) update(x, y, m + 1, r, rs[p], k, fl);
}
void dfs1(int u, int ft, int d) {
	dep[u] = d;
	fa[u] = ft;
	size[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == ft) continue;
		dfs1(to, u, d + 1);
		size[u] += size[to];
		if (size[son[u]] < size[to]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	id[u] = ++cnt;
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa[u] || to == son[u]) continue;
		dfs2(to, to);
	}
}
void addedge(int x, int y, int p, int root, bool fl) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		update(id[top[x]], id[x], 1, n, root, p, fl);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	update(id[x], id[y], 1, n, root, p, fl);
}
void link(int x1, int y1, int x2, int y2, int k) {
	addedge(x1, y1, ++tot, rta, 1);
	add(tot, tot + 1, k);
	addedge(x2, y2, ++tot, rtb, 0);
}
void un(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	}
	if (rk[x] < rk[y]) f[x] = y;
	else {
		f[y] = x;
		if (rk[x] == rk[y]) rk[x]++;
	}
}
struct node {
	int id, w;
};
bool operator < (node a, node b) {
	return a.w > b.w;
}
void dijkstra(int x) {
	memset(dis, 0x7f, sizeof(dis));
	std::priority_queue <node> q;
	q.push((node) {x, 0});
	dis[x] = 0;
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
	for (int i = 1; i <= n; i++) {
		f[i] = i;
		rk[i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &opt);
		if (opt == 1) {
			scanf("%d%d%d%d%d", &x, &y, &l, &r, &z);
			if (find(x) != find(y) || find(l) != find(r)) {
				continue;
			}
			op[++totp][1] = opt, op[totp][2] = x, op[totp][3] = y;
			op[totp][4] = l, op[totp][5] = r, op[totp][6] = z;
		}
		else {
			scanf("%d%d%d", &x, &y, &z);
			if (find(x) == find(y)) {
				continue;
			}
			op[++totp][1] = opt, op[totp][2] = x;
			op[totp][3] = y, op[totp][4] = z;
			un(x, y);
		}
	}
	for (int i = 1; i <= totp; i++) {
		if (op[i][1] == 2) {
			add(op[i][2], op[i][3], op[i][4]);
			add(op[i][3], op[i][2], op[i][4]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dep[i]) continue;
		dfs1(i, 0, 1);
		dfs2(i, i);
	}
	memset(e, 0, sizeof(e));
	memset(head, 0, sizeof(head));
	for (int i = 1; i <= totp; i++) {
		if (op[i][1] == 2) {
			add(id[op[i][2]], id[op[i][3]], op[i][4]);
			add(id[op[i][3]], id[op[i][2]], op[i][4]);
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", id[i]);
	}
	puts("");
	build(1, n, rta, 1);
	build(1, n, rtb, 0);
	deal(1, n, rta, rtb);
	// for (int i = 1; i <= totp; i++) {
	// 	if (op[i][1] == 1) {
	// 		link(op[i][2], op[i][3], op[i][4], op[i][5], op[i][6]);
	// 	}
	// }
	dijkstra(v[s]);
	for (int i = 1; i <= n; i++) {
		printf("%d ", dis[v[i]]);
	}
}
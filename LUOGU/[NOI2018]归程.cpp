#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 400100
#define LOG 22
struct Edge {
	int v, nx, w, h;
}e[MAXN << 1];
struct E {
	int u, v, w, h;
}_[MAXN];
int head[MAXN], ecnt, n, m, x, y, z, fa[MAXN], dis[MAXN], T, k, anc[MAXN][LOG + 1], p[MAXN], S, q, lst, h[MAXN], num, cnt, tt;
bool vis[MAXN];
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
bool cmp(E a, E b) {
	return a.h > b.h;
}
struct node {
	int id, w;
};
bool operator < (node a, node b) {
	return a.w > b.w;
}
void add(int f, int t, int w, int h) {
	e[++ecnt] = (Edge) {t, head[f], w, h};
	head[f] = ecnt;
}
void dijkstra(int s) {
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
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
	scanf("%d", &T);
	while (T--) {
		ecnt = 0;
		memset(head, 0, sizeof(head));
		memset(anc, 0, sizeof(anc));
		memset(p, 0, sizeof(p));
		memset(h, 0, sizeof(h));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d%d", &_[i].u, &_[i].v, &_[i].w, &_[i].h);
			add(_[i].u, _[i].v, _[i].w, _[i].h);
			add(_[i].v, _[i].u, _[i].w, _[i].h);
		}
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		lst = 0;
		dijkstra(1);
		num = n;
		std::sort(_ + 1, _ + 1 + m, cmp);
		for (int i = 1; i <= n; i++) {
			p[i] = dis[i];
		}
		cnt = 0;
		for (int i = 1; i <= m; i++) {
			x = find(_[i].u);
			y = find(_[i].v);
			if (x == y) continue;
			num++;
			fa[x] = fa[y] = num;
			anc[x][0] = anc[y][0] = num;
			fa[num] = num;
			p[num] = std::min(p[x], p[y]);
			h[num] = _[i].h;
			// printf("%d -- %d\n", x, num);
			// printf("%d -- %d\n", y, num);
			cnt++;
			if (cnt == n - 1) break;
		}
		// for (int i = 1; i <= num; i++) {
			// printf("%d ", h[i]);
		// }
		// puts("");
		// for (int i = 1; i <= num; i++) {
			// printf("%d ", p[i]);
		// }
		// puts("");
		// for (int i = 1; i <= num; i++) {
			// printf("%d ", fa[i]);
		// }
		// puts("");
		// for (int i = n + 1; i <= num; i++) {
		// 	printf("%d %d\n", p[i], h[i]);
		// }
		// puts("");
		// for (int i = n + 1; i <= num; i++) {
		// 	printf("%d ", h[i]);
		// }
		// puts("");
		// for (int i = 1; i <= n; i++) {
		// 	printf("%d\n", anc[i][0]);
		// }
		for (int j = 1; j <= LOG; j++) {
			for (int i = 1; i <= num; i++) {
				anc[i][j] = anc[anc[i][j - 1]][j - 1];
				// printf("%2d ", anc[i][j]);
			}
			// puts("");
		}
		// for (int i = 1; i <= n; i++) {
		// 	for (int j = 1; j <= LOG; j++) {
		// 		anc[i][j] = anc[anc[i][j - 1]][j - 1];
		// 		printf("%d ", anc[i][j]);
		// 	}
		// 	puts("");
		// }
		lst = 0;
		scanf("%d%d%d", &q, &k, &S);
		while (q--) {
			scanf("%d%d", &x, &y);
			tt = x;
			x = (x + lst * k - 1) % n + 1;
			y = (y + lst * k) % (S + 1);
			// printf("%d ", x);
			for (int i = LOG; i >= 0; i--) {
				if (anc[x][i] && h[anc[x][i]] > y) x = anc[x][i];
			}
			// puts("");
			printf("%d\n", p[x]);
			lst = p[x];
		}
	}
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAXN 2000100
char mp[1010][1010];
int n, m, head[MAXN], ecnt, x, y, ent[MAXN], out[MAXN], rank[MAXN], p, deli[MAXN], fa[MAXN], ans, tot;
bool vis[MAXN], ifq[MAXN];
std::queue <int> q;
struct Edge {
	int v, nx;
}e[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
void un(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rank[x] <= rank[y]) {
		fa[x] = y;
		if (rank[x] == rank[y]) {
			rank[x]++;
		}
	}
	else {
		fa[y] = x;
	}
	return;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", mp[i] + 1);
	}
	for (int i = 1; i <= n + m; i++) {
		fa[i] = i;
		rank[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mp[i][j] == '=') {
				un(i, j + n);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			x = find(j + n);
			y = find(i);
			if (mp[i][j] == '>') {
				add(x, y);
				ent[y]++;
			}
			if (mp[i][j] == '<') {
				add(y, x);
				ent[x]++;
			}
		}
	}
	tot = n + m;
	for (int i = 1; i <= n + m; i++) {
		p = find(i);
		if (!ent[p] && !ifq[p]) {
			q.push(p);
			ifq[p] = 1;
			deli[p] = 1;
			deli[i] = 1;
		}
	}
	ans = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (vis[to]) continue;
			ent[to]--;
			if (!ent[to]) {
				deli[to] = deli[u] + 1;
				q.push(to);
			}
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n + m; i++) {
		if (!ent[find(i)]) ans++;
	}
	if (tot != ans) {
		puts("No");
		return 0;
	}
	puts("Yes");
	for (int i = 1; i <= n + m; i++) {
		int p = find(i);
		deli[i] = deli[p];
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", deli[i]);
	}
	puts("");
	for (int i = n + 1; i <= n + m; i++) {
		printf("%d ", deli[i]);
	}
	return 0;
}
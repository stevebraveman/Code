#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 100100
std::vector <int> v[MAXN << 1];
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, y, k, p, lf[MAXN], s, ent[MAXN], ans, dep[MAXN], dis[MAXN], tot, lk[MAXN];
int fa[MAXN];
bool flag;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int u, int f, int d) {
	dep[u] = d;
	fa[u] = f;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		v[to].push_back(u);
		ent[u]++;
		dfs(to, u, d + 1);
	}
}
void dfs2(int r, int u, int fa) {
	tot = std::max(dep[u] - dep[r], tot);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa) continue;
		dfs2(r, to, u);
	}
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
		lk[x]++;
		lk[y]++;
	}
	dfs(1, 0, 1);
	p = n - k;
	s = n + 1;
	for (int i = 1; i <= n; i++) {
		if (lk[i] == 1) {
			v[s].push_back(i);
			ent[i]++;
		}
	}
	std::queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < v[u].size(); i++) {
			int to = v[u][i];
			ent[to]--;
			if (!ent[to]) {
				p--;
				if (!p) {
					ans = fa[to];
					flag = 1;
					break;
				}
				q.push(to);
			}
		}
		if (flag) break;
	}
	dfs2(ans, ans, fa[ans]);
	printf("%d", tot);
}
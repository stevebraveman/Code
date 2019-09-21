#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 70000
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x[MAXN], y[MAXN], in[MAXN], k;
int si[MAXN], r, anc[MAXN][20], dep[MAXN], cnt, p;
std::vector<int> v[MAXN], tv[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int i = 18; i >= 0; i--) {
		if (dep[x] - (1 << i) >= dep[y]) {
			x = anc[x][i];
		}
	}
	if (x == y) return x;
	for (int i = 18; i >= 0; i--) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0];
}
void prelca(int u) {
	p = v[u][0];
	for (int j = 1; j < (int)v[u].size(); j++) {
		p = LCA(p, v[u][j]);
	}
	// add(p, u);
	add(p, u);
	dep[u] = dep[p] + 1;
	anc[u][0] = p;
	for (int i = 1; i <= 18; i++) {
		if (anc[u][i - 1]) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	}
}
void dfs(int u) {
	si[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		// if (to == f) continue;
		dfs(to);
		si[u] += si[to];
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		while (k != 0) {
			tv[k].push_back(i);
			// _add(k, i);
			in[i]++;
			v[i].push_back(k);
			scanf("%d", &k);
		}
	}
	// puts("");
	r = n + 1;
	std::queue <int> q;
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			in[i]++;
			tv[r].push_back(i);
			// _add(r, i);
			v[i].push_back(r);
		}
	}
	q.push(r);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < (int)tv[u].size(); i++) {
			int to = tv[u][i];
			in[to]--;
			if (in[to] <= 0) {
				prelca(to);
				q.push(to);
			}
		}
	}
	dfs(r);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", si[i] - 1);
	}
	return 0;
}
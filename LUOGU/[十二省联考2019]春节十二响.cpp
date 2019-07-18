#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define ll long long
#define MAXN 200010
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN], ecnt, n, p[MAXN], x, id[MAXN], cnt;
std::priority_queue <int> q[MAXN];
std::vector<int> w;
ll ans;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void merge(int x, int y) {
	if (q[id[x]].size() < q[id[y]].size()) std::swap(id[x], id[y]);
	// printf("%d %d ", q[id[x]].size(), q[id[y]].size());
	while (!q[id[y]].empty()) {
		w.push_back(std::max(q[id[x]].top(), q[id[y]].top()));
		q[id[x]].pop();
		q[id[y]].pop();
	}
	while (!w.empty()) {
		q[id[x]].push(w.back());
		w.pop_back();
	}
	// printf("%d %d\n", q[id[x]].size(), x);
}
void dfs(int u) {
	id[u] = ++cnt;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		// printf("%d\n", to);
		dfs(to);
		merge(u, to);
	}
	q[id[u]].push(p[u]);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 2; i <= n; i++) {
		scanf("%d", &x);
		add(x, i);
	}
	dfs(1);
	while (!q[id[1]].empty()) {
		ans += 1LL * q[id[1]].top();
		q[id[1]].pop();
	}
	printf("%lld", ans);
	return 0;
}

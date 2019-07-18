#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 100010
template <typename T>
T min(T a, T b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, y, k, ans[MAXN];
int dfn[MAXN], low[MAXN], tim, st[MAXN], top, in[MAXN], num, siz[MAXN];
bool vis[MAXN];
std::vector <int> v[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		int v;
		num++;
		do {
			v = st[top--];
			vis[v] = 0;
			in[v] = num;
			siz[num]++;
		} while (v != u);
	}
}
void dfs(int u) {
	if (vis[u]) return;
	vis[u] = 1;
	v[in[u]].push_back(u);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		dfs(to);
	}
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		add(i, x);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		// v[in[i]].push_back(0);
		dfs(i);
	}
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d %d\n", in[i], siz[in[i]]);
	// }
	// puts("");
	// for (int i = 1; i <= num; i++) {
	// 	for (int j = 0; j < v[i].size(); j++) {
	// 		printf("%d ", v[i][j]);
	// 	}
	// 	puts("");
	// }
	for (int i = 1; i <= num; i++) {
		int mm = k % siz[i];
		for (int j = 0; j < (int)v[i].size(); j++) {
			ans[v[i][(mm + j) % siz[i]]] = v[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
}
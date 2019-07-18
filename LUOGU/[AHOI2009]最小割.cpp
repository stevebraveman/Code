#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000100
#define INF 2000000000
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, w, pre;
} e[MAXN];
std::queue <int> q;
int n, m, head[MAXN], ecnt = 1, x, y, z, dfn[MAXN], low[MAXN], num, top, tot;
int r, k, dep[MAXN], cur[MAXN], _tot, ans, in[MAXN], tim, st[MAXN];
bool vis[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w, f};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, f};
	head[t] = ecnt;
}
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	while (!q.empty()) q.pop();
	for (int i = 1; i <= n; i++) {
		cur[i] = head[i];
	}
	dep[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = head[v]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dep[to] > INF && e[i].w) {
				dep[to] = dep[v] + 1;
				q.push(to);
			}
		}
	}
	if (dep[t] < INF) return 1;
	else return 0;
}
int dfs(int u , int t , int l) {
	if (!l || u == t) return l;
	int fl = 0 , f;
	for (int i = cur[u] ; i ; i = e[i].nx) {
		cur[u] = i;
		int to = e[i].v;
		if (dep[to] == dep[u] + 1 && (f = dfs(to , t , min(l , e[i].w)))) {
			fl += f;
			l -= f;
			e[i ^ 1].w += f;
			e[i].w -= f;
			if (!l) break;
		}
	}
	return fl;
}
int Dinic(int s, int t) {
	int maxf = 0;
	while (bfs(s , t)) {
		maxf += dfs(s, t, INF);
	}
	return maxf;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (e[i].w) {
			if (!dfn[v]) {
				tarjan(v);
				low[u] = min(low[u], low[v]);
			}
			else if (vis[v]) low[u] = min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]) {
		num++;
		int v;
		do {
			v = st[top--];
			vis[v] = 0;
			in[v] = num;
		} while (u != v);
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &r, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
	}
	tot = Dinic(r, k);
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 2; i <= ecnt; i += 2) {
		if (!e[i].w) {
			if (in[e[i].pre] != in[e[i].v]) {
				printf("1 ");
			}
			else {
				printf("0 ");
			}
			if (in[e[i].pre] == in[r] && in[e[i].v] == in[k]) {
				puts("1");
			}
			else puts("0");
		}
		else puts("0 0");
	}
}
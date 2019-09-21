#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 1000100
#define LIM 36500
struct Edge {
	int v, nx;
}e[MAXN << 2];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int head[MAXN], ecnt, n, m, x[MAXN], y[MAXN], tim, dfn[MAXN], low[MAXN], dp[MAXN];
int f[MAXN], num, top, st[MAXN], in[MAXN], siz[MAXN], ent[MAXN], ans, tot;
bool vis[MAXN];
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
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &y[i], &x[i]);
		add(x[i], y[i]);
	}
	for (int i = 1; i <= n + 1; i++) {
		if (!dfn[i]) tarjan(i);
	}
	memset(e, 0, sizeof(e));
	memset(head, 0, sizeof(head));
	ecnt = 0;
	for (int i = 1; i <= m; i++) {
		if (x[i] == y[i]) {
			siz[in[x[i]]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (in[x[i]] != in[y[i]]) {
			add(in[x[i]], in[y[i]]);
			ent[in[y[i]]]++;
		}
	}
	std::queue <int> q;
	for (int i = 1; i <= num; i++) {
		if (!ent[i]) q.push(i);
	}
	dp[in[n + 1]] = 1;
	memset(vis, 0, sizeof(vis));
	vis[in[n + 1]] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			ent[to]--;
			if (!ent[to]) {
				q.push(to);
			}
			if (vis[u]) vis[to] = 1;
			dp[to] += dp[u];
			if (siz[to] > 1 && vis[to]) dp[to] = LIM;
			if (dp[to] > LIM) {
				dp[to] = LIM;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[in[i]]) {
			f[i] = dp[in[i]];
			ans = max(ans, f[i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[in[i]]) {
			if (f[i] == ans) tot++;
		}
	}
	if (ans == LIM) {
		puts("zawsze");
	}
	else {
		printf("%d\n", ans);
	}
	printf("%d\n", tot);
	for (int i = 1; i <= n; i++) {
		if (vis[in[i]]) {
			if (f[i] == ans) {
				printf("%d ", i);
			}
		}
	}
}
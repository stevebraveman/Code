#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAXN 1000010
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx;
}e[MAXN << 2], _e[MAXN << 2];
int head[MAXN], ecnt, _head[MAXN], _ecnt, n, m, x[MAXN], y[MAXN], dfn[MAXN], low[MAXN], p[MAXN], in[MAXN], tim, st[MAXN], top, num;
int dis1[MAXN], dis2[MAXN], ans;
bool vis[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void _add(int f, int t) {
	_e[++_ecnt] = (Edge) {t, _head[f]};
	_head[f] = _ecnt;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[v], low[u]);
		}
		else if (vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		num++;
		int v;
		do {
			v = st[top--];
			vis[v] = 0;
			in[v] = num;
			p[num]++;
		} while (u != v);
	}
}
void spfa(int s) {
	dis1[s] = p[s];
	std::queue <int> q;
	memset(vis, 0, sizeof(vis));
	vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis1[to] < dis1[u] + p[to]) {
				dis1[to] = dis1[u] + p[to];
				if (!vis[to]) {
					q.push(to);
					vis[to] = 1;
				}
			}
		}
	}
}
void _spfa(int s) {
	dis2[s] = p[s];
	std::queue <int> q;
	memset(vis, 0, sizeof(vis));
	vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = _head[u]; i; i = _e[i].nx) {
			int to = _e[i].v;
			if (dis2[to] < dis2[u] + p[to]) {
				dis2[to] = dis2[u] + p[to];
				if (!vis[to]) {
					q.push(to);
					vis[to] = 1;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		add(x[i], y[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	memset(head, 0, sizeof(head));
	ecnt = 0;
	for (int i = 1; i <= m; i++) {
		if (in[x[i]] != in[y[i]]) {
			add(in[x[i]], in[y[i]]);
			_add(in[y[i]], in[x[i]]);
		}
	}

	spfa(in[1]);
	_spfa(in[1]);
	for (int i = 1; i <= num; i++) {
		if (dis1[i]) {
			for (int j = _head[i]; j; j = _e[j].nx) {
				int to = _e[j].v;
				if (!dis2[to]) continue;
				ans = max(ans, dis1[i] + dis2[to] - p[in[1]]);
			}
		}
	}
	printf("%d\n", ans);
}
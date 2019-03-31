#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 700010
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
bool p1;
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN], x[MAXN], y[MAXN], dis[MAXN], ecnt, n, m, dfn[MAXN], low[MAXN];
int tim, num, in[MAXN], st[MAXN], top, p[MAXN], f[MAXN], s, l, k;
bool bar[MAXN], br[MAXN], vis[MAXN];
bool p2;
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
	if (dfn[u] == low[u]) {
		num++;
		int v;
		do {
			v = st[top--];
			in[v] = num;
			vis[v] = 0;
			p[num] += f[v];
			if (bar[v]) br[num] = 1;
		} while (u != v);
	}
}
std::queue <int> q;
void dp(int t) {
	q.push(t);
	dis[t] = p[t];
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if(dis[to] < dis[u] + p[to]) {
				q.push(to);
				dis[to] = dis[u] + p[to];
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
		scanf("%d", &f[i]);
	}
	scanf("%d%d", &s, &l);
	for (int i = 1; i <= l; i++) {
		scanf("%d", &k);
		bar[k] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	k = num + 1;
	memset(head, 0, sizeof(head));
	memset(e, 0, sizeof(e));
	ecnt = 0;
	for (int i = 1; i <= m; i++) {
		if (in[x[i]] != in[y[i]]) {
			add(in[x[i]], in[y[i]]);
		}
	}
	for (int i = 1; i <= num; i++) {
		if (br[i]) add(i, k);
	}
	dp(in[s]);
	printf("%d", dis[k]);
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAXN 1000002
#define INF 2000000000
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, w;
} e[MAXN];
std::queue <int> q;
int n, m, head[MAXN], ecnt = 1, x, y, z, r, k, dep[MAXN], cur[MAXN], cnt = 1, totp = 0, tot;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	while (!q.empty()) q.pop();
	for (int i = 1; i <= n + m + 2; i++) {
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
int dfs(int u, int t, int l) {
	if (!l || u == t) return l;
	int fl = 0, f;
	for (int i = cur[u]; i; i = e[i].nx) {
		cur[u] = i;
		int to = e[i].v;
		if (dep[to] == dep[u] + 1 && (f = dfs(to, t, min(l, e[i].w)))) {
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
	while (bfs(s, t)) {
		maxf += dfs(s, t , INF);
	}
	return maxf;
}
int a[MAXN], b[MAXN];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		totp += a[i];
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
	}
	r = n + m + 2;
	k = n + m + 1;
	for (int i = 1; i <= n; i++) {
		add(r, i, a[i]);
	}
	for (int i = n + 1; i <= n + m; i++) {
		add(i, k, b[i - n]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n + 1; j <= n + m; j++) {
			add(i, j, 1);
		}
	}
	tot = Dinic(r, k);
	if (tot != totp) {
		puts("0");
		return 0;
	}
	puts("1");
	for (int i = 1; i <= n; i++) {
		for (int j = head[i]; j; j = e[j].nx) {
			int to = e[j].v;
			if (to != r && e[j].w == 0) {
				printf("%d ", e[j].v - n);
			}
		}
		puts("");
	}
	return 0;
}
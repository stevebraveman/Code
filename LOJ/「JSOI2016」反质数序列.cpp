#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 1000002
#define INF 2000000000
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

struct Edge {
	int v, nx, w;
} e[MAXN];
int n, m, head[MAXN], ecnt = 1, x, y, z, r, k, dep[MAXN], cur[MAXN];
std::queue <int> q;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	while (!q.empty()) q.pop();
	for (int i = 1; i <= n + 2; i++) {
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
	int fl = 0 , f;
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
		maxf += dfs(s, t, INF);
	}
	return maxf;
}
int p[MAXN], tot, a[MAXN];
bool chk[MAXN];
void prime() {
	for (int i = 2; i <= MAXN; i++) {
		if (!chk[i]) {
			p[++tot] = i;
		}
		for (int j = 1; j <= tot; j++) {
			if (i * p[j] > MAXN) break;
			chk[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
int main() {
	scanf("%d", &n);
	prime();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1) {
			if (chk[1]) {
				i--, n--;
			}
			else chk[1] = 1;
		}
	}
	r = n + 1;
	k = n + 2;
	for (int i = 1; i <= n; i++) {
		if (a[i] & 1) {
			add(r, i, 1);
		}
		else add(i, k, 1);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] & 1) {
			for (int j = 1; j <= n; j++) {
				if (!chk[a[i] + a[j]] && (!(a[j] & 1))) {
					add(i, j, 1);
				}
			}
		}
	}
	printf("%d", n - Dinic(r, k));
	return 0;
}
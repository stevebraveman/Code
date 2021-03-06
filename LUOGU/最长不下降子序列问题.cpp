#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 1000100
#define INF 2000000000
#define re register
int a[MAXN], maxn = 0, f[MAXN];
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, w;
}e[MAXN];
std::queue <int> q;
int n, m, head[MAXN], ecnt = 1, x, y, z, r, k, dep[MAXN], cur[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	while (!q.empty()) q.pop();
	for (int i = 1; i <= k; i++) {
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
int dfs(int s, int t, int l) {
	if (!l || s == t) return l;
	int fl = 0, f;
	for (int i = cur[s]; i; i = e[i].nx) {
		cur[s] = i;
		int to = e[i].v;
		if (dep[to] == dep[s] + 1 && (f = dfs(to, t, min(l, e[i].w)))) {
			l -= f;
			fl += f;
			e[i].w -= f;
			e[i ^ 1].w += f;
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
int main() {
	scanf("%d", &n);
	r = n * 2 + 1;
	k = r + 1;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		add(i, i + n, 1);
		f[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] >= a[j]) {
				f[i] = max(f[i], f[j] + 1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		maxn = max(f[i], maxn);
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] == 1) {
			add(r, i, 1);
		}
		if (f[i] == maxn) {
			add(i + n, k, 1);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (f[i] == f[j] + 1 && a[i] >= a[j]) {
				add(j + n, i, 1);
			}
		}
	}
	printf("%d\n", maxn);
	if (maxn == 1) {
		printf("%d\n%d", n, n);
		return 0;
	}
	printf("%d\n", Dinic(r, k));
	memset(head, 0, sizeof(head));
	ecnt = 1;
	for (int i = 1; i <= n; i++) {
		if (i == 1 || i == n) {
			add(i, i + n, INF);
		}
		else add(i, i + n, 1);
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] == 1) {
			if (i == 1 || i == n) { 
				add(r, i, INF);
			}
			else add(r, i, 1);
		}
		if (f[i] == maxn) {
			if (i == 1 || i == n) {
				add(i, k, INF);
			}
			else add(i, k, 1);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (f[i] == f[j] + 1 && a[i] >= a[j]) {
				add(j + n, i, 1);
			}
		}
	}
	printf("%d\n", Dinic(r, k));
	return 0;
}
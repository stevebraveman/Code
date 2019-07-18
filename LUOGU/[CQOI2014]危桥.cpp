#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 200010
#define INF 2000000000
#define clear(x) memset(x, 0, sizeof(x));
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, w;
} e[MAXN << 2];
int head[MAXN], ecnt = 1, n, m, x, y, z, cur[MAXN], dep[MAXN], a1, a2, an, b1, b2, bn, tot, r, k;
char a[60][60];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	for (int i = 1; i <= k; i++) {
		cur[i] = head[i];
	}
	dep[s] = 0;
	std::queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dep[to] > INF && e[i].w) {
				dep[to] = dep[u] + 1;
				q.push(to);
			}
		}
	}
	return dep[t] < INF;
}
int dfs(int s, int t, int l) {
	if (s == t || !l) {
		return l;
	}
	int fl = 0, f;
	for (int i = cur[s]; i; i = e[i].nx) {
		cur[s] = i;
		int to = e[i].v;
		if (dep[to] == dep[s] + 1 && (f = dfs(to, t, min(l, e[i].w)))) {
			fl += f;
			l -= f;
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
		// puts("OK");
		maxf += dfs(s, t, INF);
	}
	return maxf;
}
int main() {
	while (scanf("%d%d%d%d%d%d%d", &n, &a1, &a2, &an, &b1, &b2, &bn) != EOF) {
		a1++, a2++, b1++, b2++;
		clear(head);
		clear(e);
		clear(cur);
		clear(dep);
		ecnt = 1;
		r = n + 1;
		k = r + 1;
		add(r, a1, an);
		add(r, b1, bn);
		add(a2, k, an);
		add(b2, k, bn);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				std::cin >> a[i][j];
				if (a[i][j] == 'O') {
					add(i, j, 1);
				}
				if (a[i][j] == 'N') {
					add(i, j, INF);
				}
			}
		}
		bool flag = 0;
		tot = Dinic(r, k);
		if (tot != an + bn) flag = 1;
		clear(head);
		clear(e);
		clear(cur);
		clear(dep);
		ecnt = 1;
		add(r, a1, an);
		add(r, b2, bn);
		add(a2, k, an);
		add(b1, k, bn);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] == 'O') {
					add(i, j, 1);
				}
				if (a[i][j] == 'N') {
					add(i, j, INF);
				}
			}
		}
		tot = Dinic(r, k);
		if (tot != an + bn) flag = 1;
		if (flag) puts("No");
		else puts("Yes");
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 100010
#define INF 2000000000
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
int head[MAXN], ecnt = 1, r, k, n, m, dep[MAXN], cur[MAXN], x, y, T, g[110][110], p, _s, _t, in[MAXN];
int tot, sum, ans;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
bool bfs(int s, int t) {
	for (int i = 1; i <= _t; i++) {
		cur[i] = head[i];
	}
	memset(dep, 0x7f, sizeof(dep));
	std::queue <int> q;
	q.push(s);
	dep[s] = 0;
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
	scanf("%d%d%d", &n, &m, &y);
	r = n + m + 1;
	k = r + 1;
	_s = k + 1;
	_t = _s + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		in[r] -= x;
		in[i] += x;
		add(r, i, INF - x);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &x);
		in[i + n] -= x;
		in[k] += x;
		add(r, i + n, INF - x);
	}
	for (int i = 1; i <= y; i++) {
		scanf("%d%d", &x, &p);
		g[x][p] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (g[i][j]) continue;
			add(i, j + n, 1);
		}
	}
	for (int i = 1; i <= k; i++) {
		if (in[i] > 0) {
			add(_s, i, in[i]);
			sum += in[i];
		}
		if (in[i] < 0) {
			add(i, _t, -in[i]);
		}
	}
	add(k, r, INF);
	tot = Dinic(_s, _t);
	if (tot != sum) {
		puts("JIONG!");
		return 0;
	}
	for (int i = head[_s]; i; i = e[i].nx) {
		e[i].w = 0;
		e[i ^ 1].w = 0;
	}
	for (int i = head[_t]; i; i = e[i].nx) {
		e[i].w = 0;
		e[i ^ 1].w = 0;
	}
	tot = e[ecnt].w;
	e[ecnt].w = e[ecnt ^ 1].w = 0;
	ans = Dinic(k, r);
	printf("%d", tot - ans);
	return 0;
}
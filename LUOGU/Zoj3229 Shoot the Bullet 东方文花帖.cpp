#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 1000100
#define INF 2000000000
#define clear(x) memset(x, 0, sizeof(x));
struct Edge {
	int v, nx, w;
} e[MAXN];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int head[MAXN], ecnt = 1, n, m, p, x, _l, _r;
int dep[MAXN], cur[MAXN], di[MAXN], r, k, ans, tot, _s, _t, _c, _d;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge){ t, head[f], w };
	head[f] = ecnt;
	e[++ecnt] = (Edge){ f, head[t], 0 };
	head[t] = ecnt;
}
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	for (int i = 1; i <= k; i++) {
		cur[i] = head[i];
	}
	std::queue<int> q;
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
	if (!l || s == t) return l;
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
		maxf += dfs(s, t, INF);
	}
	return maxf;
}
int main() {
	while (scanf("%d%d", &m, &n) != EOF) {
		_s = n + m + 1;
		_t = _s + 1;
		r = _t + 1;
		k = r + 1;
		clear(head);
		clear(di);
		ecnt = 1;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &p);
			add(i, _t, INF);
			di[i] -= p;
			di[_t] += p;
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &_c, &_d);
			add(_s, i + n, _d);
			for (int j = 1; j <= _c; j++) {
				scanf("%d%d%d", &x, &_l, &_r);
				x++;
				add(i + n, x, _r - _l);
				di[i + n] -= _l;
				di[x] += _l;
			}
		}
		for (int i = 1; i <= n + m + 2; i++) {
			if (di[i] > 0) {
				ans += di[i];
				add(r, i, di[i]);
			}
			else {
				add(i, k, -di[i]);
			}
		}
		add(_t, _s, INF);
		tot = Dinic(r, k);
		if (tot != ans) puts("-1");
		else {
			printf("%d\n", Dinic(_s, _t));
		}
		puts("");
	}
	return 0;
}
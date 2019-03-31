#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000010
#define INF 2000000000
struct Edge {
	int v, nx, w;
}e[MAXN << 2], _e[MAXN << 2];
struct E {
	int x, y;
}a[MAXN << 2];
int _head[MAXN], head[MAXN], ecnt = 1, _ecnt, n, m, col[MAXN], dep[MAXN], cur[MAXN];
int dfn[MAXN], low[MAXN], tim, st[MAXN], top, num, in[MAXN], r, k, cnt;
bool vis[MAXN];
bool cmp(E x, E y) {
	return x.x < y.x || (x.x == y.x && x.y < y.y);
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
void _add(int f, int t) {
	_e[++_ecnt] = (Edge) {t, _head[f], 0};
	_head[f] = _ecnt;
}
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	dep[s] = 0;
	for (int i = 1; i <= k; i++) {
		cur[i] = head[i];
	}
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
	if (!l || s == t) {
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
		maxf += dfs(s, t, INF);
	}
	return maxf;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	vis[u] = 1;
	for (int i = _head[u]; i; i = _e[i].nx) {
		int v = _e[i].v;
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
			vis[v] = 0;
			in[v] = num;
		} while (u != v);
	}
}
void dfscol(int x, int cr) {
	col[x] = cr;
	for (int i = _head[x]; i; i = _e[i].nx) {
		int to = _e[i].v;
		if (!col[to]) {
			dfscol(to, 3 - cr);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	r = n + 1;
	k = r + 1;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
		_add(a[i].x, a[i].y);
		_add(a[i].y, a[i].x);
	}
	for (int i = 1; i <= n; i++) {
		if (!col[i]) dfscol(i, 1);
	}
	for (int i = 1; i <= n; i++) {
		if (col[i] == 1) {
			add(r, i, 1);
		}
		if (col[i] == 2) {
			add(i, k, 1);
		}
	}
	memset(_head, 0, sizeof(_head));
	_ecnt = 0;
	memset(_e, 0, sizeof(_e));
	for (int i = 1; i <= m; i++) {
		if (col[a[i].x] == 1) {
			add(a[i].x, a[i].y, 1);
		}
		if (col[a[i].y] == 1) {
			add(a[i].y, a[i].x, 1);
		}
	}
	int tot = Dinic(r, k);
	for (int i = head[r]; i; i = e[i].nx) {
		int to = e[i].v;
		if (!e[i].w) {
			_add(to, r);
		}
		if (e[i].w) {
			_add(r, to);
		}
		for (int j = head[to]; j; j = e[j].nx) {
			int v = e[j].v;
			if (v == r) continue;
			if (e[j].w) {
				_add(to, v);
			}
			else {
				_add(v, to);
			}
		}
	}
	for (int i = head[k]; i; i = e[i].nx) {
		int to = e[i].v;
		if (e[i].w) {
			_add(k, to);
		}
		if (!e[i].w) {
			_add(to, k);
		}
	}
	for (int i = 1; i <= n + 2; i++) {
		if (!dfn[i]) tarjan(i);
	}
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++) {
		if (col[i] == 1) {
			for (int j = head[i]; j; j = e[j].nx) {
				int v = e[j].v;
				if (v == r) continue;
				if (!e[j].w) {
					a[++cnt].x = i;
					a[cnt].y = v;
					if (a[cnt].x > a[cnt].y) std::swap(a[cnt].x, a[cnt].y);
				}
			}
		}
	}
	tot = 0;
	for (int i = 1; i <= cnt; i++) {
		if (in[a[i].x] != in[a[i].y]) {
			if (a[i].x > a[i].y) std::swap(a[i].x, a[i].y);
			tot++;
		}
	}
	std::sort(a + 1, a + 1 + cnt, cmp);
	printf("%d\n", tot);
	for (int i = 1; i <= cnt; i++) {
		if (in[a[i].x] != in[a[i].y]) {
			printf("%d %d\n", a[i].x, a[i].y);
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define pr(x, y) make_pair((x), (y))
#define MAXN 1001000
struct Edge {
	int f, v, nx;
}e[MAXN << 2], e2[MAXN << 2];
int head[MAXN],top , ecnt, n, m, dfn[MAXN], st[MAXN], low[MAXN], ecnt1, si[MAXN], ent[MAXN];
int in[MAXN], tim, num, cnt, r, c, x[MAXN], y[MAXN], t[MAXN], head1[MAXN], f[MAXN];
bool vis[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {f, t, head[f]};
	head[f] = ecnt;
}
void _add(int f, int t) {
	e2[++ecnt1] = (Edge) {f, t, head1[f]};
	head1[f] = ecnt1;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
std::map<std::pair <int, int>, int> ha;
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
		num++;
		int v;
		do {
			v = st[top--];
			in[v] = num;
			vis[v] = 0;
			si[num]++;
		} while (u != v);
	}
}
int main() {
	scanf("%d%d", &n, &r, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &x[i], &y[i], &t[i]);
		ha[make_pair(x[i], y[i])] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (t[i] == 1) {
			
		}
		if (t[i] == 2) {
			
		}
		if (t[i] == 3) {
			if (ha[pr(x[i] + 1, y[i])]) add(i, ha[pr(x[i] + 1, y)]);
			if (ha[pr(x[i] + 1, y[i] + 1)]) add(i, ha[pr(x[i] + 1, y[i] + 1)]);
			if (ha[pr(x[i] + 1, y[i] - 1)]) add(i, ha[pr(x[i] + 1, y[i] - 1)]);
			if (ha[pr(x[i] - 1, y[i])]) add(i, ha[pr(x[i] - 1, y[i])]);
			if (ha[pr(x[i] - 1, y[i] + 1)]) add(i, ha[pr(x[i] - 1, y[i] + 1)]);
			if (ha[pr(x[i] - 1, y[i] - 1)]) add(i, ha[pr(x[i] - 1, y[i] - 1)]);
			if (ha[pr(x[i], y[i] + 1)]) add(i, ha[pr(x[i], y[i] + 1)]);
			if (ha[pr(x[i], y[i] - 1)]) add(i, ha[pr(x[i], y[i] - 1)]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= ecnt; i++) {
		if (in[e[i].f] != in[e[i].v]) {
			_add(in[e[i].f], in[e[i].v]);
			ent[e[i].f]++;
		}
	}
	for (int i = 1; i <= num; i++) {

	}
}
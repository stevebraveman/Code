#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 200010
struct Edge {
	int v, nx;
}e[MAXN << 1];
struct ques {
	int id, x, y, as;
}q[MAXN];
int t[MAXN][26], x, y, m, f[MAXN], ed[MAXN], tot, fa[MAXN], _n[MAXN], R[MAXN], low[MAXN], ans[MAXN];
int c[MAXN], head[MAXN], ecnt, _t[MAXN][26], ls[MAXN], cnt, k, L[MAXN], n, dfn[MAXN], tim;
int lowbit(int x) {
	return x & -x;
}
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
bool cmp(ques a, ques b) {
	return a.y < b.y;
}
void modi(int x, int y) {
	for (int i = x; i <= tim; i += lowbit(i)) {
		c[i] += y;
	}
}
int ask(int x) {
	int ans = 0;
	for (int i = x; i; i -= lowbit(i)) {
		ans += c[i];
	}
	return ans;
}
void build() {
	std::queue <int> q;
	memset(f, 0, sizeof(f));
	for (int i = 0; i < 26; i++) {
		if (t[0][i]) {
			q.push(t[0][i]);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < 26; i++) {
			if (t[u][i]) {
				f[t[u][i]] = t[f[u]][i];
				q.push(t[u][i]);
			}
			else t[u][i] = t[f[u]][i];
		}
	}
}
void dfs(int u, int f) {
	dfn[u] = ++tim;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs(to, u);
	}
	low[u] = tim;
}
void dfsans(int u) {
	// printf("%d\n", u);
	modi(dfn[u], 1);
	if (ls[u]) {
		for (int i = L[ls[u]]; i <= R[ls[u]]; i++) {
			q[i].as = ask(low[_n[q[i].x]]) - ask(dfn[_n[q[i].x]] - 1);
			// printf("%d %d %d %d %d %d %d\n", i, low[_n[q[i].x]], dfn[_n[q[i].x]], _n[q[i].x], ask(low[_n[q[i].x]]), ask(dfn[_n[q[i].x]] - 1), q[i].as);
		}
	}
	for (int i = 0; i < 26; i++) {
		if (_t[u][i]) {
			dfsans(_t[u][i]);
		}
	}
	modi(dfn[u], -1);
}
char s[MAXN], s2[MAXN], top;
int main() {
	scanf("%s", s);
	int p = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'P') {
			_n[++n] = p;
			ls[p] = n;
		}
		else if (s[i] == 'B') {
			p = fa[p];
		}
		else {
			int k = s[i] - 'a';
			if (!t[p][k]) t[p][k] = ++tot, fa[tot] = p;
			p = t[p][k];
		}
	}
	for (int i = 0; i <= tot; i++) {
		for (int j = 0; j < 26; j++) {
			_t[i][j] = t[i][j];
		}
	}
	build();
	for (int i = 1; i <= tot; i++) {
		add(f[i], i);
		add(i, f[i]);
	}
	// puts("OK");
	dfs(0, 0);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &q[i].x, &q[i].y);
		q[i].id = i;
	}
	std::sort(q + 1, q + 1 + m, cmp);
	for (int i = 1, j = 1; i <= m; i = j) {
		L[q[i].y] = i;
		while (q[j].y == q[i].y) j++;
		R[q[i].y] = j - 1;
	}
	// for (int i = 0; i <= tot; i++) {
	// 	printf("%d ", ls[i]);
	// }
	dfsans(0);
	// puts("OK");
	for (int i = 1; i <= m; i++) {
		ans[q[i].id] = q[i].as;
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
/*
aPaPBbP
3
1 2
1 3
2 3
 */
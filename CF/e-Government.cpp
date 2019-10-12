#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAXN 1000010
struct Edge {
	int v, nx;
}e[MAXN << 1];
int t[MAXN][26], end[MAXN], tot, f[MAXN], siz[MAXN], dep[MAXN], tim, x, l, ans, n, m;
char s[MAXN], ch[MAXN];
int head[MAXN], ecnt, c[MAXN], id[MAXN], fa[MAXN], top[MAXN], son[MAXN], vis[MAXN];
int lowbit(int x) {
	return x & -x;
}
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void chg(int p, int x) {
	for (int i = p; i <= tot; i += lowbit(i)) {
		c[i] += x;
	}
}
int ask(int p) {
	int y = 0;
	for (int i = p; i; i -= lowbit(i)) {
		y += c[i];
	}
	return y;
}
void insert(int kth, char *a) {
	int p = 0;
	for (int i = 0; a[i]; i++) {
		int k = a[i] - 'a';
		if (!t[p][k]) t[p][k] = ++tot;
		p = t[p][k];
	}
	end[kth] = p;
}
void build() {
	std::queue <int> q;
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
void dfs(int u, int f, int d) {
	dep[u] = d;
	fa[u] = f;
	siz[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs(to, u, d + 1);
		siz[u] += siz[to];
		siz[0] = 0;
		if (siz[son[u]] < siz[to]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	id[u] = ++tim;
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == son[u] || to == fa[u]) continue;
		dfs2(to, to);
	}
}
int qry(int x, int y) {
	int res = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		res += ask(id[x]) - ask(id[top[x]] - 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	res += ask(id[y]) - ask(id[x] - 1);
	return res;
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		insert(i, s);
	}
	build();
	for (int i = 1; i <= tot; i++) {
		add(i, f[i]);
		add(f[i], i);
	}
	tot++;
	dfs(0, 0, 1);
	dfs2(0, 0);
	for (int i = 1; i <= n; i++) {
		vis[i] = 1;
		chg(id[end[i]], 1);
	}
	while (m--) {
		scanf("%s", s);
		x = 0;
		if (s[0] == '+') {
			for (int i = 1; s[i]; i++) {
				x += x * 10 + s[i] - '0';
			}
			if (vis[x]) continue;
			chg(id[end[x]], 1);
			vis[x] = 1;
		}
		else if (s[0] == '-') {
			for (int i = 1; s[i]; i++) {
				x += x * 10 + s[i] - '0';
			}
			if (!vis[x]) continue;
			chg(id[end[x]], -1);
			vis[x] = 0;
		}
		else if (s[0] == '?') {
			ans = 0;
			x = 0;
			for (int i = 1; s[i]; i++) {
				x = t[x][s[i] - 'a'];
				ans += qry(0, x);
			}
			printf("%d\n", ans);
		}
	}
}
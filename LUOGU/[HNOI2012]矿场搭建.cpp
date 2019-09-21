#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
#define clear(x) memset(x, 0, sizeof(x))
#define ll long long
struct Edge {
	int v, nx;
}e[MAXN];
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int head[MAXN], ecnt, n, m, dfn[MAXN], low[MAXN], x, y, cnt, num, R, tot, p, r;
ll ans = 1;
int tim, cut[MAXN], vis[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	int flag = 0;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[v], low[u]);
			if (low[v] >= dfn[u]) {
				flag++;
				if (u != r || flag > 1) cut[u] = 1;
			}
		}
		else low[u] = min(low[u], dfn[v]);
	}
}
void dfs(int u, int t) {
	vis[u] = t;
	cnt++;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to] != t && cut[to]) {
			vis[to] = t;
			num++;
		}
		if (!vis[to] && !cut[to]) dfs(to, t);
	}
}
int main() {
	while (1) {
		scanf("%d", &m);
		n = 0;
		if (m == 0) break;
		clear(head);
		clear(dfn);
		clear(low);
		clear(cut);
		clear(vis);
		ecnt = 0;
		tim = 0;
		tot = 0;
		ans = 1;
		R = 0;
		p++;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &x, &y);
			add(x, y);
			add(y, x);
			n = max(x, max(y, n));
		}
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) r = i, tarjan(i);
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && !cut[i]) {
				cnt = num = 0;
				dfs(i, ++R);
				if (!num) {
					tot += 2;
					ans *= (ll)cnt * (cnt - 1) / 2;
				}
				if (num == 1) {
					tot++;
					ans *= (ll)cnt;
				}
			}
		}
		printf("Case %d: %d %lld\n", p, tot, ans);
	}
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
#define clear(x) memset(x, 0, sizeof(x))
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, col[MAXN], T, cnt;
bool flag;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int u, int c) {
	col[u] = c;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (col[to] == c) {
			flag = 1;
			return;
		}
		else if (!col[to]) {
			dfs(to, 3 - c);
		}
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		clear(col);
		clear(head);
		clear(e);
		ecnt = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &x, &y);
			add(x, y);
			add(y, x);
		}
		for (int i = 1; i <= n; i++) {
			if (!col[i]) dfs(i, 1);
		}
		printf("Scenario #%d:\n", ++cnt);
		if (flag == 1) {
			puts("Suspicious bugs found!");
		}
		else {
			puts("No suspicious bugs found!");
		}
		flag = 0;
	}
}
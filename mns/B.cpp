#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], ecnt, x, n, m, dep[MAXN], in[MAXN], rt = 1;
void dfs(int u, int f, int d) {
	dep[u] = d;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs(to, u, d + 1);
	}
}
void dfs2(int u, int f, int d) {
	for (int i = head[u]; i; i++) {

	}
}
int main() {
	scanf("%d", &m);
	if (m != 1) return 0;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &x);
		add(i, x);
		add(x, i);
		rt[x]++;
	}
	dfs(rt, rt, 1);
	for (int i = 1; i <= n; i++) {
		if (!(dep[i] & 1)) 
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000100
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, w, out[MAXN], in[MAXN];
double f[MAXN];
std::queue <int> q;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &w);
		add(y, x, w);
		out[x]++;
		in[x]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!in[i]) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			f[to] += (f[u] + (double)e[i].w) / (double)out[to];
			in[to]--;
			if (!in[to]) q.push(to);
		}
	}
	printf("%.2f\n", f[1]);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 100000
struct Edge {
	int v, nx;
}e[MAXN];
int head[MAXN], ecnt, n, m, x, y, in[MAXN], _in[MAXN], size;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
bool topo() {
	std::queue <int> q;
	size = 0;
	for (int i = 1; i <= n; i++) {
		in[i] = _in[i];
	}
	for (int i = 1; i <= n; i++) {
		if (!in[i]) q.push(i), size++;
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			in[to]--;
			if (!in[to]) q.push(to), size++;
		}
	}
	return size >= n;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		_in[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!_in[i]) continue;
		_in[i]--;
		if (topo()) {
			puts("YES");
			return 0;
		}
		_in[i]++;
	}
	puts("NO");
	return 0;
}
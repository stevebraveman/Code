#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 200100
struct Edge {
	int v, nx;
}e[MAXN];
int head[MAXN], ecnt, l, r, n, m, d, y, la, top, rs[MAXN], ls[MAXN], ph[MAXN];
std::vector<int> v[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
bool check(int x) {
	for (int i = 1; i <= n; i++) {
		head[i] = ls[i] = ph[i] = 0;
	}
	ecnt = 0;
	std::priority_queue <int> q;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j < (int)v[i].size(); j++) {
			add(v[i][j - 1], v[i][j]);
			ph[v[i][j]]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!ph[i]) q.push(-i);
	}
	top = 0;
	while (!q.empty()) {
		int u = q.top();
		u = -u;
		q.pop();
		top++;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			ph[to]--;
			if (!ph[to]) q.push(-to);
		}
	}
	// printf("%d\n", top);
	if (top == n) return 1;
	else return 0;
}
void last(int x) {
	for (int i = 1; i <= n; i++) {
		head[i] = ls[i] = ph[i] = 0;
	}
	ecnt = 0;
	std::priority_queue <int> q;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j < (int)v[i].size(); j++) {
			add(v[i][j - 1], v[i][j]);
			// printf("%d -> %d\n", v[i][j - 1], v[i][j]);
			// if (v[i][j] == 8) puts("OOOKOOKOKOOKOKOKO");
			ph[v[i][j]]++;
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d\n", ph[i]);
	// }
	// puts("OK");
	for (int i = 1; i <= n; i++) {
		if (!ph[i]) q.push(-i);
	}
	top = 0;
	while (!q.empty()) {
		int u = q.top();
		u = -u;
		q.pop();
		rs[++top] = u;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			ph[to]--;
			if (!ph[to]) q.push(-to);
		}
		printf("%d ", u);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &d);
		for (int j = 1; j <= d; j++) {
			scanf("%d", &y);
			v[i].push_back(y);
		}
	}
	r = m;
	l = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		// printf("%d\n", mid);
		if (check(mid)) {
			l = mid + 1;
		}
		else r = mid - 1;
	}
	last(r);
	// puts("OK");
	// for (int i = 1; i <= top; i++) {
	// 	printf("%d ", rs[i]);
	// }
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#define MAXN 500010
#define INF 0x7fffffff
struct Edge {
	int v, nx;
}e[MAXN];
int head[MAXN], ecnt, n, m, x, y, in[MAXN], in2[MAXN], k1, k2, maxa, maxaa;
std::priority_queue <int> q;
std::set <int> s;
std::set <int>::iterator it;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		in[y]++;
		in2[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			q.push(-i);
		}
	}
	while (!q.empty()) {
		int u = q.top();
		u = -u;
		if (u > maxaa) k1++;
		maxaa = std::max(maxaa, u);
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			in[to]--;
			if (!in[to]) q.push(-to);
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	if (!in2[i]) {
	// 		q.push(i);
	// 	}
	// }
	// while (!q.empty()) {
	// 	int u = q.top();
	// 	ans2[++top2] = u;
	// 	q.pop();
	// 	for (int i = head[u]; i; i = e[i].nx) {
	// 		int to = e[i].v;
	// 		in2[to]--;
	// 		if (!in2[to]) q.push(to);
	// 	}
	// }
	for (int i = 1; i <= n; i++) {
		if (!in2[i]) {
			s.insert(i);
		}
	}
	while (!s.empty()) {
		it = s.lower_bound(ans2[top2]);
		if (it == s.begin()) {
			it = s.end();
		}
		it--;
		int u = *it;
		s.erase(it);
		if (u > maxa) k2++;
		maxa = std::max(maxa, u);
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			in2[to]--;
			if (!in2[to]) s.insert(to);
		}
	}
	printf("%d\n%d", k1, k2);
}
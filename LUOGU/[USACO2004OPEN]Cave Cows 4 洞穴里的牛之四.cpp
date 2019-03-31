#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define MAXN 50010
struct point {
	int x, y;
}p[MAXN];
struct Edge {
	int v, nx;
}e[MAXN * 20];
int n, m, vis[MAXN], ecnt, head[MAXN], g[MAXN];
std::map <std::pair<int, int>, int> h;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct pt {
	int id, st;
};
std::queue <pt> q;
int bfs(int k) {
	q.push((pt) {k, 0});
	while (!q.empty()) {
		pt fd = q.front();
		q.pop();
		int u = fd.id;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (vis[to]) continue;
			if (g[to]) return fd.st + 1;
			q.push((pt) {to, fd.st + 1});
		}
	}
	return -1;
}
std::pair <int, int> pr;
int main() {
	scanf("%d%d", &n, &m);
	p[1].x = 0, p[1].y = 0;
	for (int i = 2; i <= n + 1; i++) {
		scanf("%d%d", &p[i].x, &p[i].y);
		pr = std::make_pair(p[i].x, p[i].y);
		if (h.count(pr)) continue;
		h[pr] = i;
		if (p[i].y == m) g[i] = 1;
	}
	for (int i = 1; i <= n + 1; i++) {
		for (int j = -2; j <= 2; j++) {
			for (int k = -2; k <= 2; k++) {
				if (j == 0 && k == 0) continue;
				int tx = p[i].x + j, ty = p[i].y + k;
				pr = std::make_pair(tx, ty);
				if (h.count(pr)) {
					add(i, h[pr]);
				}
			}
		}
	}
	printf("%d", bfs(1));
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1100100
#define INF 2000000000
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
std::queue <int> q;
int n, m, head[MAXN], ecnt = 1, x, y, z, r, k, dep[MAXN], cur[MAXN], tot;
void add(int f, int t, int w) {
    e[++ecnt] = (Edge) {t, head[f], w};
    head[f] = ecnt;
    e[++ecnt] = (Edge) {f, head[t], 0};
    head[t] = ecnt;
}
bool bfs(int s, int t) {
    memset(dep, 0x7f, sizeof(dep));
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n * m + m * n + 2; i++) {
        cur[i] = head[i];
    }
    dep[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = head[v]; i; i = e[i].nx) {
            int to = e[i].v;
            if (dep[to] > INF && e[i].w) {
                dep[to] = dep[v] + 1;
                q.push(to);
            }
        }
    }
    if (dep[t] < INF) return 1;
    else return 0;
}
int dfs(int u, int t, int l) {
    if (!l || u == t) return l;
    int fl = 0, f;
    for (int i = cur[u]; i; i = e[i].nx) {
        cur[u] = i;
        int to = e[i].v;
        if (dep[to] == dep[u] + 1 && (f = dfs(to, t, min(l, e[i].w)))) {
            fl += f;
            l -= f;
            e[i ^ 1].w += f;
            e[i].w -= f;
            if (!l) break;
        }
    }
    return fl;
}
int Dinic(int s, int t) {
    int maxf = 0;
    while (bfs(s, t)) {
        maxf += dfs(s, t, INF);
    }
    return maxf;
}
int g(int i, int j) {
	return i * m + j;
}
int main() {
	scanf("%d%d", &n, &m);
	r = n * m + m * n + 1;
	k = r + 1;
	tot = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &x);
			tot += x;
			int id = g(i, j);
			if ((i + j) & 1) {
				add(r, id, x);
				if (i > 1) add(id, g(i - 1, j), INF);
				if (j > 1) add(id, g(i, j - 1), INF);
				if (i < n) add(id, g(i + 1, j), INF);
				if (j < m) add(id, g(i, j + 1), INF);
			}
			else {
				add(id, k, x);
			}
		}
	}
	printf("%d\n", tot - Dinic(r, k));
	return 0;
}
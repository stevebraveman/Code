#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 10010001
#define INF 2000000000
struct Edge {
	int v, nx, w;
}e[MAXN];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int head[MAXN], ecnt = 1, n, m, x, y, dep[MAXN], cur[MAXN], map[210][210], wb[210][210], r, k, cnt;
int find[MAXN];
bool vis[MAXN], wh[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
int g(int i, int j) {
	return (i - 1) * m + j;
}
std::queue <int> q;
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	dep[s] = 0;
	while (!q.empty()) q.pop();
	q.push(s);
	for (int i = 1; i <= n * m + 2; i++) {
		cur[i] = head[i];
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dep[to] > INF && e[i].w) {
				dep[to] = dep[u] + 1;
				q.push(to);
			}
		}
	}
	if (dep[t] > INF) return 0;
	else return 1;
}
int dfs(int s, int t, int l) {
	if (!l || s == t) return l;
	int fl = 0, f;
	for (int i = cur[s]; i; i = e[i].nx) {
		int to = e[i].v;
		cur[s] = i;
		if (dep[to] == dep[s] + 1 && (f = dfs(to, t, min(l, e[i].w)))) {
			l -= f;
			fl += f;
			e[i].w -= f;
			e[i ^ 1].w += f;
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
void dfs(int now, int l) {
    if (vis[now]) return ;
    vis[now] = 1;
    if (wh[now] == l) {
        find[now] = 1;
    }
    for (int i = head[now]; i; i = e[i].nx) {
        if (e[i].w == l) dfs(e[i].v, l);
    }
}
int main() {
	scanf("%d%d", &n, &m);
	r = n * m + 1;
	k = n * m + 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char a;
			std::cin >> a;
			if (a == '.') {
				map[i][j] = 1;
				cnt++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		wb[i][1] = wb[i - 1][1] ^ 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			wb[i][j] = wb[i][j - 1] ^ 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] && wb[i][j]) {
				add(r ,g(i , j), 1);
				wh[g(i, j)] = 1;
				if (map[i + 1][j]) add(g(i, j), g(i + 1, j), 1);
				if (map[i - 1][j]) add(g(i, j), g(i - 1, j), 1);
				if (map[i][j + 1]) add(g(i, j), g(i, j + 1), 1);
				if (map[i][j - 1]) add(g(i, j), g(i, j - 1), 1);
			}
			if (map[i][j] && !wb[i][j]) {
				add(g(i, j), k, 1);
			}
		}
	}
	int tot = Dinic(r, k);
	if (cnt == tot) {
		puts("LOSE");
		return 0;
	}
	puts("WIN");
	dfs(r, 1);
	dfs(k, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (find[g(i, j)]) {
				printf("%d %d\n", i, j);
			}
		}
	}
	return 0;
}
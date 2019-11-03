// Dinic m sqrt(n)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000010
#define INF 2000000000
struct Edge {
	int v, nx, w;
}e[MAXN << 3];
int head[MAXN], ecnt = 1, cur[MAXN], n, m, x, y, dep[MAXN];
int g1[110][110], g2[110][110], _s, _t, col[110][110];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
char s[MAXN];
int g(int i, int j) {
	return (i - 1) * m + j;
}
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
bool bfs(int s, int t) {
	for (int i = 1; i <= _t; i++) {
		dep[i] = 0x7fffffff;
		cur[i] = head[i];
	}
	std::queue <int> q;
	dep[s] = 1;
	q.push(s);
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
	return dep[t] < INF;
}
int dfs(int s, int t, int l) {
	if (s == t || !l) {
		return l;
	}
	int fl = 0, f;
	for (int i = cur[s]; i; i = e[i].nx) {
		int to = e[i].v;
		cur[s] = i;
		if (dep[to] == dep[s] + 1 && (f = dfs(to, t, std::min(e[i].w, l)))) {
			fl += f;
			l -= f;
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
bool chk(int x, int y, int tx, int ty) {
	int p1 = g2[x][y];
	int p2 = g2[tx][ty];
	if (p1 == p2) {
		if (x == tx) {
			if (p1 == 1 || p1 == 4) return 0;
			if (p1 == 2 || p1 == 3) return 1;
		}
		else {
			if (p1 == 1 || p1 == 4) return 1;
			if (p1 == 2 || p1 == 3) return 0;
		}
	}
	if (p1 + p2 == 5) {
		if (x == tx) {
			if (p1 == 1 || p1 == 4) return 1;
			else return 0;
		}
		else {
			if (p1 == 2 || p2 == 3) return 1;
			else return 0;
		}
	}
	else return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++) {
			if (s[j] == 'R') {
				g1[i][j] = 1;
			}
		}
	}
	_s = n * m + 1;
	_t = _s + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++) {
			if (s[j] == 'L') g2[i][j] = 1;
			else if (s[j] == 'R') g2[i][j] = 4;
			else if (s[j] == 'U') g2[i][j] = 3;
			else if (s[j] == 'D') g2[i][j] = 2;
		}
	}
	if ((n == 1) && (m == 2)) {
		if (g1[1][1] == g1[1][2]) {
			puts("0");
			return 0;
		}
		if (chk(1, 1, 1, 2)) puts("1");
		else puts("0");
		return 0;
	}
	if ((n == 2) && (m == 1)) {
		if (g1[1][1] == g1[2][1]) {
			puts("0");
			return 0;
		}
		if (chk(1, 1, 2, 1)) puts("1");
		else puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			col[i][j] = ((i + j) & 1);
			if (!col[i][j]) {
				add(_s, g(i, j), 1);
			}
			else {
				add(g(i, j), _t, 1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 4; k++) {
				if (col[i][j]) continue;
				int tx = i + dx[k], ty = j + dy[k];
				if (tx <= 0 || ty <= 0 || tx > n || ty > m) continue;
				if (g1[tx][ty] == g1[i][j]) continue;
				add(g(i, j), g(tx, ty), 1);
			}
		}
	}
	printf("%d", Dinic(_s, _t));
	return 0;
}
/*
2 2
RL
LR
UR
LU

3 2
LR
RR
LL
LU
DL
LL
 */
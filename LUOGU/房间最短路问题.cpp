#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 100010
struct Edge {
	int v, nx;
	double w;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m;
bool vis[MAXN];
double dis[MAXN], a[22][5];
void add(int f, int t, double w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
int g(int i, int j) {
	return i + (j - 1) * 4;
}
void spfa(int s) {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n * 4 + 2; i++) {
		dis[i] = 9999999.9999;
	}
	std::queue <int> q;
	q.push(s);
	vis[s] = 1;
	while (!q.empty()) {
		int f = q.front();
	}
}
int main() {

}
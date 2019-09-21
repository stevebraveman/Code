#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define MAXN 1000100
#define INF 2000000000
using std::string;
std::map <string, int> h;
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, fl, w;
}e[MAXN];
int n, m, s, t, head[MAXN], dis[MAXN], ecnt = 1, k;
int flow[MAXN], maxf, minc, la[MAXN], pre[MAXN], x[MAXN], y[MAXN], z[MAXN], f[MAXN];
bool vis[MAXN];
std::queue <int> q;
void add(int f, int t, int fl, int w) {
	e[++ecnt] = (Edge) {t, head[f], fl, w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, -w};
	head[t] = ecnt;
}
bool spfa(int s, int t) {
	memset(dis, 0x7f, sizeof(dis));
	memset(flow, 0x7f, sizeof(flow));
	memset(vis, 0, sizeof(vis));
	pre[t] = -1;
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vis[v] = 0;
		for (int i = head[v]; i; i = e[i].nx) {
			int f = e[i].fl;
			int to = e[i].v;
			if (f > 0 && dis[to] > dis[v] + e[i].w) {
				dis[to] = dis[v] + e[i].w;
				pre[to] = v;
				la[to] = i;
				flow[to] = min(flow[v], f);
				if (!vis[to]) {
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
	return pre[t] != -1;
}
void mcmf(int s, int t) {
	while (spfa(s, t)) {
		int v = t;
		maxf += flow[t];
		minc += flow[t] * dis[t];
		while (v != s) {
			int k = la[v];
			e[k].fl -= flow[t];
			e[k ^ 1].fl += flow[t];
			v = pre[v];
		}
	}
}
string a, b;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		std::cin >> a;
		h[a] = i;
	}
	for (int i = 1; i <= m; i++) {
	}
}
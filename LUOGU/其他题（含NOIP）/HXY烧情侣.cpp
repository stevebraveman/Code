#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 100021
#define MOD 1000000007
struct Edge {
	int v, nx;
}e[MAXN << 2];
int tim, st[MAXN], in[MAXN], ecnt, y, n, m, my[MAXN], p[MAXN], minn[MAXN];
int head[MAXN], dfn[MAXN], low[MAXN], x, dis[MAXN], top, tot, ans1 = 1, ans2, num, k[MAXN];
bool vi[MAXN], vis[MAXN];
std::vector<int> ve[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	vi[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[v], low[u]);
		}
		else if (vi[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		num++;
		int v;
		do {
			v = st[top--];
			vi[v] = 0;
			in[v] = num;
			ve[num].push_back(v);
			my[num] = min(my[num], p[v]);
		} while (v != u);
	}
}
int main() {
	memset(my, 0x7f, sizeof(my));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) 
			tarjan(i);
	}
	for (int i = 1; i <= num; i++) {
		for (int j = 0; j < (int)(ve[i].size()); j++) {
			if (p[ve[i][j]] == my[i]) {
				k[i]++;
			}
		}
	}
	for (int i = 1; i <= num; i++) {
		ans1 *= k[i] % MOD;
		ans2 += my[i];
	}
	printf("%d %d", ans2, ans1);
	return 0;
}
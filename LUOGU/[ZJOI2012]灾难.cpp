#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 1001000
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, in[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		while (x != 0) {
			scanf("%d", &x);
			add(i, x);
			in[x]++;
		}
	}
	std::queue <int> q;
}
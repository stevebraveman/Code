#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 5000101
struct Edge {
	int u, v, w;
	double f;
	bool ifuse;
}a[MAXN];
int n, m, f[MAXN], dp;
bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%f", &a[i].u, &a[i].v, &a[i].w, &a[i].f);
	}
	
}
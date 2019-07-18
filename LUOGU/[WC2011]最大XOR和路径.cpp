#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000010
struct Edge {
	int v, nx, z;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, y, z, a[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] =ecnt;
}
void bfs(int s) {
	for (int i = head[s]; i; i = e[i].nx) {
		int to = e[i].v;

	}
}
void insert(int k) {
	for (int i = 63; i >= 0; i--) {

	}
}
int main() {
	
}
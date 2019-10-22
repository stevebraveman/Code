#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 150060
struct Edge {
	int v, nx;
}e[MAXN];
int ecnt, head[MAXN], n, m, x, y, in[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void topo() {

}
int main() {
}
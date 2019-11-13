#include <iostream>
#include <cstdio>
#include <cstdio>
#include <cstring>
#define MAXN 1000010
struct Edge {
	int u, v, w;
}e[MAXN];
int n, m;
bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}
int main() {
	
}
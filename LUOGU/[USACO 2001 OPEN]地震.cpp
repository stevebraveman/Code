#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10010
struct Edge {
	int u, v, a, b;
	double w;
}e[MAXN << 1];
double l, r = 1000000.0, F;
int n, m, fa[MAXN];
bool cmp(Edge a, Edge b) {
	return a.w > b.w;
}
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
bool un(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return 0;
	fa[x] = y;
	return 1;
}
bool check(double x) {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		e[i].w = -1.0 * e[i].a - e[i].b * x;
	}
	double tot = 0.0;
	std::sort(e + 1, e + 1 + m, cmp);
	// for (int i = 1; i <= m; i++) {
	// 	printf("%f ", e[i].w);
	// }
	// puts("");
	for (int i = 1; i <= m; i++) {
		if (un(e[i].u, e[i].v)) {
			tot += e[i].w;
		}
	}
	return F + tot >= 0.0;
}
int main() {
	scanf("%d%d%lf", &n, &m, &F);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].a, &e[i].b);
	}
	while (r - l > 0.000001) {
		double mid = (l + r) / 2.0;
		// printf("%f\n", mid);
		if (check(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	printf("%.4f", l);
}
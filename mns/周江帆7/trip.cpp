#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 7010
struct planet {
	double x, y;
}p[MAXN];
int fa[MAXN], n, m, k, rk[MAXN];
bool up[MAXN], dw[MAXN];
double l, r;
double dis(planet a, planet b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
void un(int x, int y) {
	if (x == y) return;
	if (rk[x] < rk[y]) fa[x] = y;
	else {
		fa[y] = x;
		if (rk[x] == rk[y]) rk[x]++;
	}
}
bool chk(double x) {
	// puts("-----");
	for (int i = 1; i <= k; i++) {
		fa[i] = i;
		rk[i] = 1;
		up[i] = dw[i] = 0;
	}
	for (int i = 1; i <= k; i++) {
		// printf("%lf %lf\n", p[i].y, 1.0 * n - p[i].y);
		if (p[i].y <= 2 * x) {
			dw[i] = 1;
			// printf("%lf %d down\n", p[i].y, i);
		}
		if (1.0 * m - p[i].y <= 2 * x) {
			up[i] = 1;
			// printf("%lf %d up\n", n - p[i].y, i);
		}
	}
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j < i; j++) {
			int t = find(i), y = find(j);
			if (t == y && ((up[i] && dw[j]) || (up[j] && dw[i]))) {
				return 0;
			}
			if (dis(p[i], p[j]) <= x * 2) {
				un(t, y);
			}
		}
	}
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j < i; j++) {
			if (find(i) == find(j) && ((up[i] && dw[j]) || (up[j] && dw[i]))) {
				return 0;
			}
		}
	}
	return 1;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}
	r = m / 2.0;
	while (r - l > 0.000001) {
		double mid = (l + r) / 2.0;
		// printf("%lf\n", mid);
		if (chk(mid)) {
			l = mid;
		}
		else r = mid;
	}
	// l = 1.263;
	printf("%.7lf", l);
	return 0;
}
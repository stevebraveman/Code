#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2502
int n, head[MAXN], ecnt, x, y, p[MAXN], s[MAXN], k, siz[MAXN];
double a[MAXN][MAXN], l, r, mid, tp[MAXN], val[MAXN];
struct Edge {
	int v, nx;
}e[MAXN << 2];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void Tree_dp(int u) {
	siz[u] = 1;
	a[u][0] = 0.0;
	a[u][1] = val[u];
	for(int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		// if (to == fa) continue;
		Tree_dp(to);
		for (int j = 1; j <= siz[to] + siz[u]; j++) {
			tp[j] = -999999.99;
		}
		// puts("");
		for (int j = 1; j <= siz[u]; j++) {
			for (int d = 0; d <= siz[to]; d++) {
				tp[j + d] = std::max(tp[j + d], a[to][d] + a[u][j]);
			}
		}
		siz[u] += siz[to];
		for (int j = 1; j <= siz[u]; j++) a[u][j] = tp[j];
	}
}
bool check(double x) {
	memset(a, 0xc, sizeof(a));
	// printf("%.4f\n", x);
	for (int i = 1; i <= n; i++) {
		val[i] = (double)p[i] - (double)s[i] * x;
	}
	Tree_dp(0);
	// printf("%.5f\n", a[0][k + 1]);
	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 1; j <= k + 1; j++) {
	// 		printf("%.4f ", a[i][j]);
	// 	}
	// 	puts("");
	// }
	// puts("--------");
	if (a[0][k + 1] > 0) return 1;
	else return 0;
}
int main() {
	scanf("%d%d", &k, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &s[i], &p[i], &x);
		r = std::max((double)p[i] / (double)s[i], r);
		add(x, i);
	}
	while (r - l > 1e-4) {
		mid = (l + r) / 2;
		// printf("%.5f %.5f\n", l, r);
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%.3f", l);
	return 0;
}
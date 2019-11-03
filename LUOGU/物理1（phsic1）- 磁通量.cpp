#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstring>
#include <cmath>
#define MAXN 100010
struct point {
	double x, y;
}p[MAXN];
int n;
double s, B;
int main() {
	scanf("%d%lf", &n, &B);
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}
	// for (int i = 1; i <= n; i++) {
	// 	printf("%lf %lf\n", p[i].x, p[i].y);
	// }
	for (int i = 1; i < n; i++) {
		s += (p[i].x * p[i + 1].y - p[i + 1].x * p[i].y);
	}
	s += (p[n].x * p[1].y - p[1].x * p[n].y);
	s = s * 0.5;
	s = fabs(s);
	printf("%.4lf\n", B * s);
}
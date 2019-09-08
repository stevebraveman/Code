#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#define sqr(x) ((x) * (x))
#define MAXN 100010
#define delt 0.997
struct G {
	double x, y, w;
}p[MAXN];
int n;
double ansx, ansy, anst = 1e18 + 7;
double check(double x, double y) {
	double ans = 0.0;
	for (int i = 1; i <= n; i++) {
		ans += sqrt(sqr(x - p[i].x) + sqr(y - p[i].y)) * p[i].w;
	}
	return ans;
}
void SA() {
	double t = 2500.0;
	double _x = ansx;
	double _y = ansy;
	while (t > 1e-15) {
		double deltx = ansx + (rand() * 2 - RAND_MAX) * t;
		double delty = ansy + (rand() * 2 - RAND_MAX) * t;
		double k = check(deltx, delty);
		double dt = k - anst;
		// printf("%.2f %.2f\n", deltx, delty);
		if (dt < 0) {
			_x = deltx;
			_y = delty;
			ansx = _x;
			ansy = _y;
			anst = k;
		}
		else if (exp(-dt / t) * RAND_MAX > rand()) {
			_x = deltx;
			_y = delty;
		}
		t *= delt;
	}
}
int main() {
	srand(time(NULL));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i].x >> p[i].y >> p[i].w;
	}
	SA();
	SA();
	SA();
	SA();
	printf("%.3f %.3f", ansx, ansy);
}
#include <iostream>
#include <cstdio>
using namespace std;
double a , b , c , d;
double f(double x) {
	return a * x * x * x + b * x * x + c * x + d;
}
void solve(double x , double y) {
	double mid;
	while (y - x >= 0.0001) {
		mid = x + (y - x) / 2;
		if (f(mid) < 0.001 && f (mid) > -0.001) {
			printf ("%.2lf " , mid);
			return;
		}
		if (f(x) * f(mid) <= 0) y = mid;
		else x = mid;
	}
	return;
}
int main() {
	// cin >> a >> b >> c >> d;
	scanf("%lf %lf %lf %lf", &a , &b , &c , &d);
	for (double i = -100 ; i <= 100 ; i += 1.0) {
		if (f(i) == 0.0) {
			printf("%.2lf " , i);
			continue;
		}
		if (f(i) * f(i + 1.0) <= 0) {
			solve (i , i + 1.0);
		}
	}
	return 0;
}
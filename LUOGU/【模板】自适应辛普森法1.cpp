#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
double a, b, c, d, L, R, k;
int main() {
	std::cin >> a >> b >> c >> d >> L >> R;
	if (a == 0) {
		k = (c * R * R + 2 * d * R) / (2 * b) - (c * L * L + 2 * d * L) / (2 * b);
		printf("%.6lf", k);
		return 0;
	}
	k = ((a * d - b * c) * log(fabs(a * R + b)) + a * c * R) / (a * a) - ((a * d - b * c) * log(fabs(a * L + b)) + a * c * L) / (a * a);
	printf("%.6lf", k);
	return 0;
}
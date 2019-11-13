#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
long long x1, y1, z1, x2, y2, z2;
int main() {
	while(scanf("%lld%lld%lld%lld%lld%lld", &x1, &y1, &z1, &x2, &y2, &z2) != EOF) {
		printf("%lld %lld %lld\n", y1 * z2 - z1 * y2, z1 * x2 - x1 * z2, x1 * y2 - y1 * x2);
	}
	return 0;
}
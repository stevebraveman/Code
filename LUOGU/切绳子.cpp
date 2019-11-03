#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100010
double a[MAXN];
int n, k, l, r;
bool chk(double x) {
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		tot += a[i] / x;
	}
	return tot >= k;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &a[i]);
		a[i] *= 100;
	}
	r = 0x7fffffff;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (!mid) break;
		if (chk(mid)) {
			l = mid + 1;
		}
		else r = mid - 1;
	}
	printf("%.2f", r / 100.0);
}
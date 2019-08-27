#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
long long a1, a2, n, d, ans, k;
int main() {
	scanf("%lld%lld%lld", &a1, &a2, &n);
	d = a2 - a1;
	k = n * (n - 1);
	ans = n * a1 + k * d / 2;
	printf("%lld", ans);
	return 0;
}
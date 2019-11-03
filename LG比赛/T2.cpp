#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 300010
int a[MAXN], n;
long long la[MAXN];
bool cmp(int a, int b) {
	return a > b;
}
double ans = 0.0;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	std::sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		la[i] = la[i - 1] + 1LL * a[i];
	}
	for (int i = 1; i <= n; i++) {
		ans = std::max(ans, 1.0 * la[i] / i * la[i]);
	}
	printf("%.8lf", ans);
}
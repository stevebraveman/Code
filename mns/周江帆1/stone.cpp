#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 100100
int n, a[MAXN];
double ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		ans += (double)i / n;
	}
	printf("%.6f\n", ans);
}
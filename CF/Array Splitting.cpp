#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 300100
int a[MAXN], n, k, sub[MAXN], ans;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 2; i <= n; i++) {
		sub[i - 1] = a[i] - a[i - 1];
	}
	std::sort(sub + 1, sub + n, cmp);
	for (int i = 1; i <= n; i++) {
		ans += sub[i];
	}
	for (int i = 1; i <= k - 1; i++) {
		ans -= sub[i];
	}
	printf("%d", ans);
	return 0;
}
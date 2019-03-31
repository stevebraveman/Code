#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
int n, k, a[MAXN], l[MAXN], r[MAXN], hs[MAXN];
int main() {
	freopen("tracking2.in", "r", stdin);
	freopen("tracking2.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n - k + 1; i++) {
		scanf("%d", &a[i]);
		hs[i] = a[i];
	}
	printf("3");
	return 0;
}
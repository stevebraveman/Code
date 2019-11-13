#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
int k, n, a[MAXN];
long long f[MAXN];
int main() {
	scanf("%d%d", &k, &n);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &a[i]);
	}
	f[0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = a[i]; j <= n; j++) {
			f[j] = f[j] + f[j - a[i]];
		}
	}
	printf("%lld", f[n]);
	return 0;
}
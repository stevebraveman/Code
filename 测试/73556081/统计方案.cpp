#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 1 << 17
int a[MAXN], n, p, k, ans = 1, tot;
int main() {
	scanf("%d%d%d", &n, &p, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= ((1 << n) - 1); i++) {
		ans = 1;
		for (int j = 1; j <= n; j++) {
			if (i & (1 << (j - 1))) {
				ans = 1LL * ans * a[j] % p;
			}
		}
		if (ans == k) {
			tot++;
		}
	}
	printf("%d", tot);
}
/*
2 7 2
1 2
*/
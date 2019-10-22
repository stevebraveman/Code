#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
int n, k, a[MAXN], maxa, tot;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (k == 1) {
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				maxa = std::max(a[i] & a[j], maxa);
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (maxa == (a[i] & a[j])) {
					tot++;
				}
			}
		}
		printf("%d %d", maxa, tot);
	}
	else if (k == 2) {
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				maxa = std::max(a[i] ^ a[j], maxa);
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (maxa == (a[i] ^ a[j])) {
					tot++;
				}
			}
		}
		printf("%d %d", maxa, tot);
	}
	else {
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				maxa = std::max(a[i] | a[j], maxa);
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (maxa == (a[i] | a[j])) {
					tot++;
					// printf("%d %d %d %d", a[i], a[j], i, j);
				}
			}
		}
		// puts("OK");
		printf("%d %d", maxa, tot);
	}
}
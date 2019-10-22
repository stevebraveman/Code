#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
int a[MAXN], c, b, n, m, col[MAXN], ans = 0;
int main() {
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &col[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (col[i] == b) {
				a[i] ^= 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i - 1] == 0 && a[i] == 1) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 550
int f[MAXN][MAXN], a[MAXN], n, m, b[MAXN], dp[MAXN];
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				f[i][j] = f[i - 1][j - 1] + 1;
			}
			else {
				f[i][j] = max(f[i][j - 1], f[i - 1][j]);
			}
		}
	}
}
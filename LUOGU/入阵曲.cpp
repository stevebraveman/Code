#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 410
int a[MAXN][MAXN], n, m, k, b[MAXN][MAXN], tot[5001000], t[MAXN];
long long sum;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			b[i][j] = a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			b[i][j] = (a[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + k) % k;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			tot[0] = 1;
			for (int p = 1; p <= m; p++) {
				t[p] = (b[j][p] + k - b[i][p]) % k;
				sum += tot[t[p]]++;
			}
			for (int p = 1; p <= m; p++) {
				tot[t[p]] = 0;
			}
		}
	}
	printf("%lld\n", sum);
}
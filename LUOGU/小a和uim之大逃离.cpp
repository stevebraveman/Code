#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MOD 1000000007
int map[810][810], k, n, m, f[810][810][17][2], ans = 0;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	k++;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			f[i][j][map[i][j] % k][0] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int p = 0; p <= k; p++) {
				f[i][j][p][0] = (f[i][j][p][0] + f[i - 1][j][(p - map[i][j] + k) % k][1]) % MOD;
				f[i][j][p][0] = (f[i][j][p][0] + f[i][j - 1][(p - map[i][j] + k) % k][1]) % MOD;
				f[i][j][p][1] = (f[i][j][p][1] + f[i - 1][j][(p + map[i][j]) % k][0]) % MOD;
				f[i][j][p][1] = (f[i][j][p][1] + f[i][j - 1][(p + map[i][j]) % k][0]) % MOD;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = (ans + f[i][j][0][1]) % MOD;
		}
	}
	printf("%d", ans % MOD);
}
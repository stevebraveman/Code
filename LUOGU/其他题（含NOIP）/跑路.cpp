#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
int g[60][60][70], mp[60][60], n, m, x, y;
int main() {
	scanf("%d%d", &n, &m);
	memset(mp, 0x3f, sizeof(mp));
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		mp[x][y] = 1;
		g[x][y][0] = 1;
	}
	for (int k = 1; k <= 69; k++) {
		for (int p = 1; p <= n; p++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (g[i][p][k - 1] && g[p][j][k - 1]) {
						g[i][j][k] = 1;
						mp[i][j] = 1;
					}
				}
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mp[i][j] = std::min(mp[i][j], mp[i][k] + mp[k][j]);
			}
		}
	}
	printf("%d", mp[1][n]);
	return 0;
}
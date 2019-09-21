#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 210
int a[maxn][maxn], n, m, k, x, y, z, ans, key[maxn][maxn][maxn], b[maxn][maxn], c[maxn][maxn];
bool fl, pres;
int main() {
	scanf("%d%d", &n, &m);
	memset(a, 0x3f, sizeof(a));
	memset(c, 0x3f, sizeof(c));
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = z;
		a[y][x] = z;
		c[x][y] = c[y][x] = z;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = std::min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			key[0][i][j] = c[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		memcpy(key[k], key[k - 1], sizeof(key[k - 1]));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				key[k][i][j] = std::min(key[k][i][j], key[k][i][k] + key[k][k][j]);
			}
		}
	}
	for (int p = 1; p <= n; p++) {
		memcpy(b, key[p - 1], sizeof(key[p - 1]));
		for (int k = p + 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (k != p) {
						b[i][j] = std::min(b[i][j], b[i][k] + b[k][j]);
					}
				}
			}
		}
		//puts("-------");
		//for (int i = 1; i <= n; i++) {
		//for (int j = 1; j <= n; j++) {
		//printf("%d ", b[i][j]);
		//}
		//puts("");
		//}
		//puts("-------");
		fl = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				/*printf("%d %d %d %d\n", b[i][j], a[i][j], i, j);*/
				if (i != p && j != p && b[i][j] > a[i][j] && i != j) {
					printf("%d ", p);
					pres = 1;
					fl = 1;
					break;
				}
			}
			if (fl) break;
		}
	}
	if (!pres) {
		puts("No important cities.");
	}
	return 0;
}

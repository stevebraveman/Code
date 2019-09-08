#include <iostream>
#include <cstdio>
#include <cstring>
int G[60][60][1010], n, m, q, x, y, z;
double E[60][60];
bool ifna[60][60];
int main() {
	scanf("%d%d", &n, &m);
	memset(G, 0x3f, sizeof(G));
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		if (G[x][y][1] > z) {
			G[x][y][1] = z;
		}
	}
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			E[i][j] = 999999999.0;
		}
	}
	for (int l = 2; l <= m; l++) {
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (G[i][j][l] > G[i][k][l - 1] + G[k][j][1]) {
						G[i][j][l] = G[i][k][l - 1] + G[k][j][1];
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (G[i][j][k] != 0x3f3f3f3f) {
					E[i][j] = std::min((double)G[i][j][k] / (double)k, E[i][j]);
				}
			}
			if (E[i][j] == 999999999.0) ifna[i][j] = 1;
		}
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &x, &y);
		if (ifna[x][y]) puts("OMG!");
		else printf("%.3f\n", E[x][y]);
	}
}
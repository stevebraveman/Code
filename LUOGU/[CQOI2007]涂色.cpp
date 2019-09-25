#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 55
char s[MAXN], a[MAXN];
int f[MAXN][MAXN], n, m;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
scanf("%d", pp);

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	memset(f, 0x7f, sizeof(f));
	for (int i = 1; i <= n; i++) {
		f[i][i] = 1;
	}
	for (int l = 1; l < n; l++) {
		for (int i = 1, j = 1 + l; j <= n; j++, i++) {
			if (s[i] == s[j]) {
				f[i][j] = min(f[i][j - 1], f[i + 1][j]);
				// printf("%d %d %d %d %d\n", i + 1, j - 1, f[i][j - 1], f[i + 1][j], f[i][j]);
			}
			else {
				for (int k = i; k < j; k++) {
					f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
				}
				// printf("%d\n", f[i][j]);
			}
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		printf("%d ", f[i][j]);
	// 	}
	// 	puts("");
	// }
	printf("%d", f[1][n]);
	return 0;
}
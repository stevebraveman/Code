#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MOD 2015
int n , k , f[1005][1005];
int main() {
	scanf("%d%d" , &n , &k);
	for (int i = 1 ; i <= n ; i++) {
		f[i][0] = 1;
		f[i][i - 1] = 1;
	}
	for (int i = 2 ; i <= n ; i++) {
		for (int j = 1 ; j <= k ; j++) {
			f[i][j] = (((i - j) * f[i - 1][j - 1] % MOD) + ((j + 1) * f[i - 1][j] % MOD) % MOD);
		}
	}
	printf("%d" , f[n][k] % MOD);
	return 0;
}
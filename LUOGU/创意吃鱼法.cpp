#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2505
int a[MAXN][MAXN] , n , m , dp[MAXN][MAXN] , f1[MAXN][MAXN] , f2[MAXN][MAXN] , ans = 0;
int min(int a , int b) {
	if (a < b) return a;
	else return b;
}
int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			scanf("%d" , &a[i][j]);
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			if (!a[i][j]) {
				f1[i][j] = f1[i][j - 1] + 1;
				f2[i][j] = f2[i - 1][j] + 1;
			}
			else {
				dp[i][j] = min(dp[i - 1][j - 1] , min(f1[i][j - 1] , f2[i - 1][j])) + 1;
				ans = max(dp[i][j] , ans);
			}
		}
	}
	memset(dp , 0 , sizeof(dp));
	memset(f1 , 0 , sizeof(f1));
	memset(f2 , 0 , sizeof(f2));
	for (int i = 1 ; i <= n ; i++) {
		for (int j = m ; j >= 1 ; j--) {
			if (!a[i][j]) {
				f1[i][j] = f1[i][j + 1] + 1;
				f2[i][j] = f2[i - 1][j] + 1;
			}
			else {
				dp[i][j] = min(dp[i - 1][j + 1] , min(f1[i][j + 1] , f2[i - 1][j])) + 1;
				ans = max(dp[i][j] , ans);
			}
		}
	}
	printf("%d" , ans);
}

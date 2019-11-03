#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 4010
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int ansc[MAXN], l1, l2, maxl, nx[MAXN][2], nx2[MAXN][2], p1, p2, dp[MAXN][MAXN], top;
char s1[MAXN], s2[MAXN];
bool chk(char *a, char *b) {
	int i = 0, j = 0;
	int n = strlen(a + 1), m = strlen(b + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] == b[i]) {

		}
	}
}
int main() {
	scanf("%d%d", &l1, &l2);
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	maxl = max(l1, l2);
	for (int i = l1; i; i--) {
		for (int j = 0; j < 2; j++) {
			nx[i - 1][j] = nx[i][j];
		}
		nx[i - 1][s1[i] - '0'] = i;
	}
	for (int i = l2; i; i--) {
		for (int j = 0; j < 2; j++) {
			nx2[i - 1][j] = nx2[i][j];
		}
		nx2[i - 1][s2[i] - '0'] = i;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= l1; j++) {
			printf("%d ", nx[j][i]);
		}
		puts("");
	}
	// for (int i = maxl - 1; i >= 0; i++) {
	// 	if ()
	// }
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= l1; j++) {
			printf("%d ", nx2[j][i]);
		}
		puts("");
	}
	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++) {
			for (int k = 0; k < 2; k++) {
				int x = nx[i][k], y = nx2[j][k];
				dp[x][y] = std::min(dp[x][y], dp[i][j] + 1);
			}
			printf("%d ", dp[i][j]);
		}
		puts("");
	}
	// p1 = p2 = 1;
	do {
		// puts("");
		if (dp[p1][p2] + 1 == dp[nx[p1][0]][nx2[p2][0]]) ansc[++top] = 0, p1 = nx[p1][0], p2 = nx2[p2][0];
		else if (dp[p1][p2] + 1 == dp[nx[p1][1]][nx2[p2][1]]) ansc[++top] = 1, p1 = nx[p1][1], p2 = nx2[p2][1];
	} while (p1 != 0 && p2 != 0);
	for (int i = 1; i <= top; i++) {
		printf("%d ", ansc[i]);
	}
	return 0;
}
/*
4 7
0101
1100001
1 3 3 0 0
2 2 4 4 0
3 3 3 4 5 6 0 0
1 2 7 7 7 7 7 0
 */
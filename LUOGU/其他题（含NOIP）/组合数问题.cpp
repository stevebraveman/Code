#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2002
int c[MAXN][MAXN] , t , k , m , n , s[MAXN][MAXN] = {0};
void deal() {
	c[1][1] = 1;
	for (int i = 0 ; i <= 2000 ; i++) {
		c[i][0] = 1;
	}
	for (int i = 2 ; i <= 2000 ; i++) {
		for (int j = 1 ; j <= i ; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k;
		}
	}
	for (int i = 2 ; i <= 2000 ; i++) {
		for (int j = 1 ; j <= i ; j++) {
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
			if (c[i][j] == 0) {
				s[i][j]++;
			}
			s[i][i + 1] = s[i][i];
		}
	}
}
int main() {
	memset(c , 0 ,sizeof(c));
	memset(s , 0 ,sizeof(c));
	scanf("%d%d" , &t , &k);
	deal();
	while (t--) {
		scanf("%d%d" , &n , &m);
		if (n < m) m = n;
		printf("%d\n" , s[n][m]);
	}
}
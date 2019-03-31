#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 106
#define INF 19260817
int n , m , n1[MAXN] , n2[MAXN] , f[MAXN][MAXN];
char s1[MAXN] , s2[MAXN];
int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
int tab[6][6] = {{0 , 0 , 0 , 0 , 0 , 0},
				 {0 , 5 , -1 , -2 , -1 , -3},
				 {0 , -1 , 5 , -3 , -2 , -4},
				 {0 , -2 , -3 , 5 , -2 , -2},
				 {0 , -1 , -2 , -2 , 5 , -1},
				 {0 , -3 , -4 , -2 , -1 , 0}};
int main() {
	scanf("%d" , &n);
	for (int i = 1 ; i <= n ; i++) {
		std::cin >> s1[i];
	}
	scanf("%d" , &m);
	for (int i = 1 ; i <= m ; i++) {
		std::cin >> s2[i];
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			f[i][j] = -INF;
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		if (s1[i] == 'A') n1[i] = 1;
		if (s1[i] == 'C') n1[i] = 2;
		if (s1[i] == 'G') n1[i] = 3;
		if (s1[i] == 'T') n1[i] = 4;
	}
	for (int i = 1 ; i <= m ; i++) {
		if (s2[i] == 'A') n2[i] = 1;
		if (s2[i] == 'C') n2[i] = 2;
		if (s2[i] == 'G') n2[i] = 3;
		if (s2[i] == 'T') n2[i] = 4;
	}
	for (int i = 1 ; i <= n ; i++) {
		f[i][0] = f[i - 1][0] + tab[n1[i]][5];
	}
	for (int i = 1 ; i <= m ; i++) {
		f[0][i] = f[0][i - 1] + tab[n2[i]][5];
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			f[i][j] = max(f[i][j] , f[i][j - 1] + tab[n2[j]][5]);
			f[i][j] = max(f[i][j] , f[i - 1][j] + tab[n1[i]][5]);
			f[i][j] = max(f[i][j] , f[i - 1][j - 1] + tab[n1[i]][n2[j]]);
		}
	}
	printf("%d" , f[n][m]);
}

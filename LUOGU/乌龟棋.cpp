#include <iostream>
#include <cstring>
#include <cstdio>
int n , m , a[5] , r , x , b[351] , f[41][41][41][41];
inline int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , &b[i]);
	}
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d" , &x);
		a[x]++;
	}
	for (int i = 0 ; i <= a[1] ; i++) {
		for (int j = 0 ; j <= a[2] ; j++) {
			for (int p = 0 ; p <= a[3] ; p++) {
				for (int q = 0; q <= a[4] ; q++) {
					r = 1 + i + j * 2 + p * 3 + q *4;
					if(i != 0) f[i][j][p][q] = max(f[i][j][p][q] , f[i - 1][j][p][q] + b[r]);
					if(j != 0) f[i][j][p][q] = max(f[i][j][p][q] , f[i][j - 1][p][q] + b[r]);
					if(p != 0) f[i][j][p][q] = max(f[i][j][p][q] , f[i][j][p - 1][q] + b[r]);
					if(q != 0) f[i][j][p][q] = max(f[i][j][p][q] , f[i][j][p][q - 1] + b[r]);
				}
			}
		}
	}
	printf("%d" , f[a[1]][a[2]][a[3]][a[4]] + b[1]);
	return 0;
}
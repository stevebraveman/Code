#include <iostream>
#include <cstdio>
#include <cstring>
#define re register
int n , p , q , k , f[5005][5005] = {0}, ans = 0;
inline int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	scanf("%d%d" , &n , &k);
	p = q = k;
	for (re int i = 1 ; i <= n ; i++) {
		int x , y , z;
		scanf("%d%d%d" , &x , &y , &z);
		x++;
		y++;
		p = max(x , p);
		q = max(y , q);
		f[x][y] = z;
	}
	for (re int i = 1 ; i <= p ; i++) {
		for (re int j = 1 ; j <= q ; j++) {
			f[i][j] = f[i][j] + f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1];
		}
	}
	for (re int i = k ; i <= p ; i++) {
		for (re int j = k ; j <= q ; j++) {
			ans = max(ans , f[i][j] + f[i - k][j - k] - f[i - k][j] - f[i][j - k]);
		}
	}
	printf("%d" , ans);
}
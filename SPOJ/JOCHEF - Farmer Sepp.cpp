#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 4002
int max(int a , int b) {
	if(a > b) return a;
	else return b;
}
int min(int a , int b) {
	if(a < b) return a;
	else return b;
}
int a[MAXN][MAXN], f[MAXN][MAXN], l[MAXN][MAXN], r[MAXN][MAXN];
int L[MAXN][MAXN], R[MAXN][MAXN], h[MAXN][MAXN], n, m, ans = 0, ansj = 0, tmp, k;
int solve() {
	for (int i = 1; i <= n; i++) {
		tmp = 0;
		for (int j = 1; j <= m ; j++){
			if (a[i][j]){
				l[i][j] = tmp;
			}
			else {
				tmp = j;
				L[i][j] = 0;
			}
		}
		tmp = m + 1;
		for (int j = m; j >= 1 ; j--){
			if (a[i][j]) {
				r[i][j] = tmp;
			}
			else {
				tmp = j;
				R[i][j] = m + 1;
			}
		}
	}
	for (int i = 1 ; i <= m ; i++) {
		R[0][i] = m + 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j]) {
				h[i][j] = h[i - 1][j] + 1;
				L[i][j] = max(L[i - 1][j], l[i][j]);
				R[i][j] = min(R[i - 1][j], r[i][j]);
				ansj = max(ansj, h[i][j] * (R[i][j] - L[i][j] - 1));
			}
		}
	}
}
int main() {
	while (1) {
		scanf("%d%d", &n, &m);
		ansj = 0;
		if (n == 0 || m == 0) return 0;
		scanf("%d", &k);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				char c;
				std::cin >> c;
				if (c == 'H') a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		solve();
		printf("%lld\n", 1LL * ansj * k);
	}
	return 0;
}
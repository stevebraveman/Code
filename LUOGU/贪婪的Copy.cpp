#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
int ans = 0 , n , a[105][105] , p , x[15] , minn = 19260817;
int min(int a , int b) {
	if (a < b) return a;
	else return b;
}
int main() {
	scanf("%d" , &n);
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			scanf("%d" , &a[i][j]);
		}
	}
	for (int k = 1 ; k <= n ; k++) {
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= n ; j++) {
				a[i][j] = min(a[i][j] , a[i][k] + a[k][j]);
			}
		}
	}
	scanf("%d" , &p);
	for (int i = 1 ; i <= p ; i++) {
		scanf("%d" , &x[i]);
	}
	std::sort(x + 1 , x + 1 + p);
	do {
		ans = 0;
		ans += a[x[p]][n];
		ans += a[1][x[1]];
		for (int i = 1 ; i < p ; i++) {
			ans += a[x[i]][x[i + 1]];
		}
		minn = min(ans , minn);
	} while (std::next_permutation(x + 1 , x + 1 + p));
	printf("%d", minn);
	return 0;
}
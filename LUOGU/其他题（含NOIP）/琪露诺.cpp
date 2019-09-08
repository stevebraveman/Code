#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200002
void swap(int &a , int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}
int n , l , r , a[MAXN] , q[MAXN][2] , f[MAXN], h = 1 , t;
int main() {
	scanf("%d%d%d" , &n , &l , &r);
	for (int i = 0 ; i <= n ; i++) {
		scanf("%d" , &a[i]);
	}
	for (int i = n ; i >= n - l + 1 ; i--) {
		f[i] = a[i];
	}
	for (int i = n + 1 ; i >= l ; i--) {
		while (t >= h && f[i] > q[t][0]) t--;
		t++;
		q[t][0] = f[i];
		q[t][1] = i;
		f[i - l] = q[h][0] + a[i - l];
		if (i + r == q[h][1]) h++;
	}
	printf("%d" , f[0]);
}
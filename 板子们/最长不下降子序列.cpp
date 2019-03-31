#include <iostream>
#include <cstdio>
int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
int n , a[5005] , f[5005] , maxa = 0;
int main() {
	scanf("%d" , &n);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , &a[i]);
		f[i] = 1;
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j < i ; j++) {
			if (a[i] >= a[j]) {
				f[j] = max(f[i] , f[j] + 1);
			}
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		maxa = max(f[i] , maxa);
	}
	printf("%d" , maxa);
}
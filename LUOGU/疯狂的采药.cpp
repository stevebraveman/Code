#include <iostream>
#include <cstring>
#include <cstdio>
int n , m , f[1000002] , w[100002] , v[100002] , ac = 9 , ak = 7;
int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	memset(f , 0 , sizeof (f));
	scanf("%d%d" , &m , &n);
	for (int i = 1 ; i <= n ; i++) {
		scanf ("%d%d" , &w[i] , &v[i]);
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = w[i] ; j <= m ; j++) {
			f[j] = max(f[j] , f[j - w[i]] + v[i]);
		}
	}
	int ans = 0;
	for (int j = 0 ; j <= m ; j++) {
		ans = max(f[j] , ans);
	}
	printf("%d" , ans);
	return 0;
}
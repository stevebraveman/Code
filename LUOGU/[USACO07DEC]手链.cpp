#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
int n , m , ans = 0 , w[3402] , v[3402] , f[13000];
inline int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d%d" , &w[i] , &v[i]);
	}
	memset(f , 0xcf , sizeof(f));
	f[0] = 0;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = m ; j >= w[i] ; j--) {
			f[j] = max(f[j] , f[j - w[i]] + v[i]);
		}
	}
	for (int i = 0 ; i <= m ; i++) {
		ans = max(ans , f[i]);
	}
	printf("%d" , ans);
}
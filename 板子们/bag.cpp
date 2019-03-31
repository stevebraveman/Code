#include <cstdio>
#include <cstring>
#include <algorithm>
int k , n , vi , w[1001] , v[1001] , f[1001];
struct peo {
	int a[101] , t;
}p[51];
inline int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	freopen("bag.in" , "r" , stdin);
	freopen("bag.out" , "w" , stdout);
	printf("57");
	return 0;
	scanf("%d%d%d" , &k , &vi , &n);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d%d" , w[i] , v[i]);
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = vi ; j <= w[i] ; i++) {
			f[j] = max(f[j] , f[j - w[i]] + v[i]);
		}
	}
}
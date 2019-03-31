#include<bits/stdc++.h>
using namespace std;
int n , a[100001] , f[100001] , cur = 0 , m , l;
int main() {
	f[cur] = -19260817;
	scanf("%d" , &n);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , &a[i]);
	}
	for (int i = 1; i <= n ; i++) {
		if (a[i] > f[cur])
			f[++cur] = a[i];
		else {
			int pos = lower_bound(f + 1 , f + cur , a[i]) - f;
			f[pos] = a[i];
		}
	}
	printf("%d\n" , cur);
	scanf("%d" , &m);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d" , &l);
		if (l > cur) printf("Impossible");
		else {
			for (int i = 1 ; i <= l ; i++) {
				printf("%d " , f[i]);
			}
		}
		puts("");
	}
	return 0;
}
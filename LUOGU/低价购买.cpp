#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 5005
#define re register
int a[MAXN] , maxn = 0 , f[MAXN] , c[MAXN] , n;
int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	scanf("%d",&n);
	memset(a , 0 , sizeof(a));
	memset(f , 0 , sizeof(f));
	memset(c , 0 , sizeof(c));
	for(re int i = 1; i <= n; i ++) {
		scanf("%d",&a[i]);
	}
	for (re int i = 1 ; i <= n; i ++) {
		maxn = max(maxn,f[i]);
	}
	for (re int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j < i ; j++) {
			if (a[i] < a[j]) {
				f[i] = max(f[i] , f[j] + 1);
			}
		}
		if (f[i] == 0) f[i]++;
		if (f[i] > maxn) maxn = f[i];
		for (re int j = 1 ; j < i ; j++) {
			if (a[j] > a[i] && f[i] == f[j] + 1) {
				c[i] += c[j];
			}
			else if (a[j] == a[i] && f[i] == f[j]) {
				c[j] = 0;
			}
		}
		if (!c[i]) c[i] = 1;
	}
	int ans = 0;
	for(re int i = 1; i <= n; i ++) {
		if(f[i] == maxn)
			ans += c[i];
	}
	printf("%d %d\n" , maxn  , ans);
	return 0;
}
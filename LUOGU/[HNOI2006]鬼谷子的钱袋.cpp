#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 1000005
int n , a[MAXN] , tot;
int main() {
	scanf("%d" , &n);
	while (n) {
		a[++tot] = (n + 1) >> 1;
		n >>= 1;
	}
	printf("%d\n" , tot);
	for (int i = tot ; i >= 1 ; i--) {
		printf("%d " , a[i]);
	}
}
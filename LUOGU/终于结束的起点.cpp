#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100000000
int f[MAXN] , m , i , n;
int main() {
	f[1] = 1;
	f[0] = 0;
	scanf("%d" , &n);
	for (i = 2 ; i <= 10000000LL ; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % n;
		if (f[i] == 0 && f[i + 1] == 1) break;
	}
	printf("%d\n" , i);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
int n , m , t , l , ans = 0 , la = 0 , a;
int main () {
	scanf("%d" , &t);
	for (int i = 1 ; i <= t ; i++) {
		ans = 0;
		la = 0;
		scanf("%d" , &n);
		for (int i = 1 ; i <= n ; i++) {
			scanf("%d" , &a);
			if ((n - i + 1) & 1) ans ^= (a - la);
			la = a;
		}
		if (ans != 0) {
			printf("TAK\n");
		}
		else {
			printf("NIE\n");
		}
	}
	return 0;
}
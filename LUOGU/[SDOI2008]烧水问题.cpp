#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
int n;
double c , ans = 0.0;
int main() {
	scanf("%d" , &n);
	c = 420000.000 / (double)n;
	for (int i = 1 ; i <= n ; i++) {
		ans += c;
		c *= (1 - 0.5 / (double)i);
	}
	printf("%.2f" , ans);
}
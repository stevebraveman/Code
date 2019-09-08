#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define R 0.5772156649
#define ll long long
int n;
double ans = 0.0;
int main() {
	scanf("%d" , &n);
	if (n <= 1000000) {
		for (int i = 1 ; i <= n ; i++) {
			ans += 1.0 / (double)i;
		}
	}
	else {
		ans = log((double)n + 1) + R;
	}
	printf("%.8lf" , ans);
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
long long n, k;
bool prime(long long k) {
	for (long long i = 2; i <= sqrt(k); i++) {
		if (k % i == 0) return 0; 
	}
	return 1;
}
int main() {
	scanf("%lld%lld", &n, &k);
	if (prime(k + 1)) {
		if ((n + 1) >= (k + 1) * 2) printf("2");
		else printf("1");
	}
	else printf("2");
}
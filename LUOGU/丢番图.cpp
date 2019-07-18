#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define ll long long
#define MAXN 10000010
ll n, ans = 1, p;
int main() {
	scanf("%lld", &n);
	for (int i = 2; i <= sqrt(n); i++) {
		p = 0;
		while (n % i == 0) p++, n /= (i * 1LL);
		ans *= (p * 2 + 1);
		// printf("%d %lld\n", i, ans);
	}
	if (n > 1) ans *= 3;
	printf("%lld", (ans + 1) / 2);
}
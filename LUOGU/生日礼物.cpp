#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100010
#define ll long long
ll a, n, m = 1, tot, k, sq;
int main() {
	scanf("%lld", &n);
	sq = sqrt(n);
	for (int i = 2; i <= sqrt(n); i++) {
		tot = 0;
		while (n % i == 0) {
			tot++;
			n /= i;
		}
		m *= (tot * 2 + 1);
	}
	if (n > 1) m *= (2 + 1);
	printf("%lld", m);
	return 0;
}
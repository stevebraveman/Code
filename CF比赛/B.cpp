#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define MAXN 1000010
int n, a[MAXN], k;
ll ans, _tot, tot;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		tot += a[i];
	}
	std::sort(a + 1, a + n + 1);
	k = n / 2;
	for (int i = 1; i <= k; i++) {
		_tot += a[i];
	}
	tot -= _tot;
	printf("%I64d", 1ll * _tot * _tot + 1ll * tot * tot);
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
int n, m, a[MAXN], b[MAXN], a1, a2, b1, b2;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a1 += (a[i] & 1);
		a2 += ((a[i] & 1) ^ 1);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		b1 += (b[i] & 1);
		b2 += ((b[i] & 1) ^ 1);
	}
	printf("%d", std::min(a1, b2) + std::min(a2, b1));
	return 0;
}

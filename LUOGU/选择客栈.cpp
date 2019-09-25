#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200010
#define LOG 20
int n, c[MAXN], w[MAXN], p, col, ncol, sum[MAXN], tot, la[MAXN], t[MAXN];
int main() {
	scanf("%d%d%d", &n, &col, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &c[i], &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (w[i] <= p) {
			ncol = i;
		}
		if (ncol >= la[c[i]]) {
			sum[c[i]] = t[c[i]];
		}
		t[c[i]]++;
		la[c[i]] = i;
		tot += sum[c[i]];
	}
	printf("%d\n", tot);
	return 0;
}
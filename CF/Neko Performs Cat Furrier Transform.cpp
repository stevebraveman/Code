#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1001000
int n, a[MAXN], tot, m, p, i;
bool chk(int x) {
	return (x & (x - 1)) == 0;
}
int high(int x) {
	for (int i = 19; i >= 0; i--) {
		if ((x >> i) & 1) return i;
	}
	return -1;
}
int main() {
	scanf("%d", &n);
	m = n;
	while(!chk(m + 1)) {
		i++;
		if (i % 2 == 0) {
			m++;
			continue;
		}
		p = high(m);
		if ((1 << p) != m) p++;
		m ^= ((1 << p) - 1);
		a[++tot] = p;
	}
	printf("%d\n", i);
	for (int j = 1; j <= tot; j++) {
		printf("%d ", a[j]);
	}
	return 0;
}
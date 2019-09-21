#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
int p[2000100];
int n, m, M = 10, N = 89, key = 1;
int main() {
	scanf("%d%d", &n, &m);
	while (M % N && key <= m) {
		M *= 10;
		p[key] = M / N;
		M %= N;
		key++;
	}
	for (int i = n; i <= m; i++) {
		printf("%d", p[i]);
	}
	return 0;
}
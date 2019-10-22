#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
int main() {
	int n = rand() % 25 + 1;
	printf("%d\n", n);
	for (int i = 1; i <= n; i++) {
		int x = rand() % 2;
		printf("%d", x);
	}
}
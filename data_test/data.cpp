#include <bits/stdc++.h>
#include <windows.h>
#include <process.h>
#define random(a, b) rd() % ((b) - (a) + 1) + (a)
int p[100005], tot = 1, bj[100005], G[510][510];
int rd() {
	unsigned long long a = rand(), b = rand(), c = rand();
	a <<= 41;
	b <<= 12;
	c <<= 30;
	a |= b;
	b ^= c;
	a |= b;
	return (int)(a % 2147483647);
}
int main() {
	srand(getpid());
	int n, m;
	n = random(14, 15);
	printf("%d\n", n);
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			int x = random(1, 1000000000);
			printf("%d ", x);
		}
		puts("");
	}
	return 0;
}
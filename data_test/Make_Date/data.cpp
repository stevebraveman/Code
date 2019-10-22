#include <bits/stdc++.h>
#include <process.h>
#define random(a, b) (rd() % ((b) - (a) + 1) + (a))
int rd() {
	unsigned long long a = rand() * rand(), b = rand() * rand(), c = rand() * rand();
	a <<= 17;
	b >>= 25;
	c <<= 54;
	a |= b;
	a ^= c;
	return a % 2147483647;
}
int main() {
	srand(getpid());
	int n = random(99800, 100000);
	int m = random(800, 1000);
	int k1 = sqrt(n) * log2(n);
	int k2 = log2(n) * log(n);
	int fl = rand() % 2;
	int k = random((int)sqrt(n), (fl == 1 ? k1 : k2));
	printf("%d %d %d\n", n, m, k);
	for (int i = 1; i <= n; i++) {
		int x = random(0, m - 1);
		printf("%d ", x);
	}
}
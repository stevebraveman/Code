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
	n = random(480, 500);
	m = random(1, n * (n - 1) / 2 - 1);
	printf("%d %d\n", n, m);
	for (int i = 1; i <= m; i++) {
		int x = random(1, n), y = random(1, n);
		while (G[x][y] || G[y][x] || x == y) {
			x = random(1, n);
			y = random(1, n);
		}
		G[x][y] = G[y][x] = 1;
		printf("%d %d\n", x, y);
	}
	return 0;
}
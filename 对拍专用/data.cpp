#include <bits/stdc++.h>
#define random(a, b) rand() % ((b) - (a) + 1) + (a)
int randposi(int a) {
	int t = rand() % 2;
	if (t == 1) return -a;
	else return a;
}
int main() {
	srand(time(NULL));
	int n, m;
	n = 10;
	printf("%d\n", n);
	for (int i = 1; i <= n; i++) {
		int x = random(0, 10);
		int y = random(0, 10);
		x = randposi(x);
		y = randposi(y);
		printf("%d %d\n", x, y);
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
int a[2000][2000], n, d, x1, y1;
void shm(int x) {
	if (x == 1) {
		a[x][x] = 1;
		return;
	}
	int _x = x / 2;
	// printf("%d %d\n", x, y);
	shm(_x);
	for (int i = _x + 1; i <= x; i++) {
		for (int j = 1; j <= _x; j++) {
			a[i][j] = a[i - _x][j];
		}
	}
	for (int i = 1; i <= _x; i++) {
		for (int j = _x + 1; j <= x; j++) {
			a[i][j] = a[i][j - _x];
		}
	}
	return;
}
int main() {
	scanf("%d", &n);
	x1 = (1 << n);
	y1 = (1 << n);
	shm(x1);
	for (int i = (1 << n); i >= 1; i--) {
		for (int j = (1 << n); j >= 1; j--) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
}
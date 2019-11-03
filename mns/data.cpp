#include <bits/stdc++.h>
#include <windows.h>
#include <process.h>
#define MAXN 100100
int main() {
	srand(getpid());
	int n = rand() % 15 + 1, m = rand() % 15 + 1;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) {
		int x = rand() % m + 1;
		printf("%d ", x);
	}
}
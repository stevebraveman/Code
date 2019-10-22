#include <bits/stdc++.h>
#include <windows.h>
#include <process.h>
#define random(a, b) (rand() % ((b) - (a) + 1) + (a))
#define MAXN 100010
int n, a, num[MAXN], m, l;
void tree_print(int n){
	for(register int i = 2; i <= n; ++i) {
		int x = rand() % (i - 1) + 1;
		while (num[x] == l) {
			x = rand() % (i - 1) + 1;
		}
		printf("%d %d\n", x, i);
		num[i]++;
		num[x]++;
	}
}
int main() {
	srand(getpid());
	srand(rand() + 19260817);
	n = random(99000, 100000);
	m = random(99000, 100000);
	l = random(400, 500);
	printf("%d %d %d\n", n, m, l);
	tree_print(n);
	for (int i = 1; i <= m; i++) {
		int x = random(1, n), y = random(1, n);
		while (x == y) {
			x = random(1, n);
			y = random(1, n);
		}
		int k = random(1, std::min(n, l));
		printf("%d %d %d\n", x, y, k);
	}
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d ", num[i]);
	// }
	return 0;
}
#include <bits/stdc++.h>
#include <process.h>
#define random(a, b) rand() % ((b) - (a) + 1) + (a)
int p[100005], tot = 1, bj[100005];
bool cmp(int a, int b) {
	return a > b;
}
struct node {
	int id, w;
}a[101000];
bool cmp2(node a, node b) {
	if (a.w != b.w) return a.w < b.w;
	else return a.id < b.id;
}
int main() {
	srand(getpid());
	int n, m;
	n = 10;
	m = 3;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	std::random_shuffle(p + 1, p + 1 + n);
	// std::sort(p + 1, p + 1 + n, cmp);
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d\n", p[i]);
	// }
	for (int i = 1; i <= n; i++) {
		printf("%d ", p[i]);
	}
	puts("");
	for (int i = 1; i <= m; i++) {
		int x = random(1, n);
		int y = random(1, n);
		while (x == y) {
			x = random(1, n);
			y = random(1, n);
		}
		printf("%d %d\n", x, y);
	}
	
	int q = 5;
	printf("%d\n", q);
	for (int i = 1; i <= q; i++) {
		int fl = random(1, 2);
		if (fl == 1) {
			int x = random(1, n);
			int y = random(1, m);
			while (x == y) {
				x = random(1, n);
				y = random(1, n);
			}
			printf("B %d %d\n", x, y);
		}
		else {
			int x = random(1, n);
			int y = random(1, 3);
			printf("Q %d %d\n", x, y);
		}
	}
	return 0;
}
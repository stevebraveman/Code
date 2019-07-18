#include <bits/stdc++.h>
int rd() {
	unsigned int p = rand() << 12, q = rand() << 2, k = rand();
	return p ^ q ^ k;
}
std::vector<int> v[50];
int x[50], y[50], cnt;
int random(int a, int b) {
	return (rd() % ((b) - (a) + 1) + (a));
}
int main() {
	freopen("data.in", "w", stdout);
	srand(time(NULL));
	int n, m, T = 5000;
	printf("%d", T);
	puts("");
	while (T--) {
		n = random(1, 10000000);
		m = random(1, 10000000);
		printf("%d %d\n", n, m);
	}
}
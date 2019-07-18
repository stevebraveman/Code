#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
int T, m, k, p, b[MAXN];
char n;
int work(int *a, int p) {
	int ans = 0;
	if (p == 0) {
		ans++;
	}
	while (1) {
		if (a[1] & 1) {
			a[1]--;
		}
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &k, &p);
		for (int i = 1; i <= k; i++) {
			std::cin >> n;
			b[k - i + 1] = n - '0';
		}
		printf("%d\n", work(b, p, k));
	}
}
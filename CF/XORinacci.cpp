#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
int a, b, n, T, ans;
int c1[] = {1, 1, 0}, c2[] = {1, 0, 1}, c3[] = {0, 1, 1};
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &a, &b, &n);
		// if (n == 0) {
		// 	printf("%d\n", a);
		// 	continue;
		// }
		// if (n == 1) {
		// 	printf("%d\n", b);
		// 	continue;
		// }
		// if (n == 2) {
		// 	printf("%d\n", a ^ b);
		// 	continue;
		// }
		if (n == 0) {
			printf("%d\n", a);
			continue;
		}
		if (n == 1) {
			printf("%d\n", b);
			continue;
		}
		ans = 0;
		std::bitset <32> p(a), q(b);
		int k[32] = {0};
		for (int i = 0; i <= 31; i++) {
			if (!p.test(i) && !q.test(i)) {
				k[i] = 0;
				continue;
			}
			else if (p.test(i) && q.test(i)) {
				k[i] = c1[n % 3];
				continue;
			}
			else if (p.test(i) && !q.test(i)) {
				k[i] = c2[n % 3];
				// printf("%d %d %d %d %d %d\n", k[i], i, c1[n % 3], c1[0], c1[1], c1[2], n % 3);
				continue;
			}
			else if (!p.test(i) && q.test(i)) {
				k[i] = c3[n % 3];
				continue;
			}
		}
		for (int i = 0; i < 32; i++) {
			ans += (k[i]) << i;
			// printf("%d ", k[i]);
		}
		// puts("");
		printf("%d", ans);
		puts("");
	}
}
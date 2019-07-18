#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 500010
int a[MAXN], n, T, num[3], ans;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			a[i] %= 3;
		}
		for (int i = 1; i <= n; i++) {
			num[a[i]]++;
		}
		ans = num[0];
		if (num[1] < num[2]) {
			num[2] -= num[1];
			ans += num[1];
			ans += num[2] / 3;
		}
		else if (num[1] == num[2]) {
			ans += num[2];
		}
		else if (num[1] > num[2]) {
			num[1] -= num[2];
			ans += num[2];
			ans += num[1] / 3;
		}
		printf("%d\n", ans);
	}
}
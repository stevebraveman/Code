#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 10000000
int phi[MAXN + 10], tot, p[MAXN + 10], ans[MAXN + 10];
bool chk[MAXN + 10];
void seive(int n) {
	phi[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= tot && p[j] * i <= n; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				phi[i * p[j]] = phi[i] * phi[p[j]];
			}
			else {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans[i] = 0x7fffffff;
	}
	for (int i = 1; i <= n; i++) {
		ans[phi[i]] = std::min(ans[phi[i]], i);
	}
}
int n;
int main() {
	freopen("phi.in", "r", stdin);
	freopen("phi.out", "w", stdout);
	seive(MAXN);
	scanf("%d", &n);
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d\n", phi[i]);
	// }
	if (ans[n] == 0x7fffffff) {
		// puts("OK");
		if (!chk[n + 1]) {
			printf("%d", n + 1);
		}
		else puts("-1");
		return 0;
	}
	printf("%d\n", ans[n]);
}
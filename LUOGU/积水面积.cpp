#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10010
int a[MAXN], n, maxa, p[MAXN], top, ans = 0, lpos, rpos, tot;
bool vis[MAXN], b[MAXN];
int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		maxa = std::max(maxa, a[i]);
		vis[a[i]] = 1;
	}
	for (int i = 1; i <= maxa; i++) {
		if (vis[i]) p[++top] = i;
	}
	for (int j = 1; j <= maxa; j++) {
		ans = 0;
		rpos = lpos = 0;
		for (int i = 0; i <= n; i++) {
			if (a[i + 1] >= j && a[i] < j) {
				lpos = i;
				break;
			}
		}
		for (int i = n + 1; i >= 1; i--) {
			if (a[i - 1] >= j && a[i] < j) {
				rpos = i;
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] >= j) {
				ans++;
			}
		}
		// printf("%d %d %d ", lpos, rpos, ans);
		ans = (rpos - 1 - lpos) - ans;
		// printf("%d\n", ans);
		tot += ans;
	}
	printf("%d\n", tot);
}

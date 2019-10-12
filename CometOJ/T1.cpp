#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
int n, m, a[MAXN], top, b[MAXN], k;
bool vis[MAXN];
bool cmp(int a, int b) {
	return a < b;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &a[i]);
		vis[a[i]] = 1;
	}
	memset(b, 0x7f, sizeof(b));
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		b[++top] = i;
	}
	std::sort(b + 1, b + 1 + top);
	k = 1;
	for (int i = 1; i <= m; i++) {
		while (b[k] < a[i]) {
			// printf("%d ----", k);
			printf("%d\n", b[k]);
			k++;
		}
		printf("%d\n", a[i]);
	}
	for (int i = k; i <= top; i++) {
		printf("%d\n", b[i]);
	}
	return 0;
}
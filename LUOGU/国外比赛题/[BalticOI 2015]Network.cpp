#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <ctime>
#define MAXN 10010000
std::queue <int> q;
int n, x, y, e[MAXN], tot, ste, p[MAXN], ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		e[x]++;
		e[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (e[i] == 1) {
			p[++tot] = i;
		}
	}
	ans = (tot + 1) >> 1;
	printf("%d", ans);
	for (int i = 1; i <= ans; i++) {
		printf("\n%d %d", p[i], p[i + ans]);
	}
	return 0;
}
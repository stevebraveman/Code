#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
int x, y, n, m;
int ans;
int main() {
	scanf("%d%d%d%d", &x, &y, &n, &m);
	ans += y * 2 + x + 4 + n + (m - 1) * 2 + x - n + 2;
	printf("%d", ans);
	return 0;
}

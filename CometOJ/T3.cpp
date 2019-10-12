#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
int n, m, a[25][25], r[21], c[21], r1[21], c1[21], top, ans;
bool check(int x, int y) {
	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
	int tr = 0, tc = 0;
	for (int i = 0; i <= 20; i++) {
		r[i + 1] = (((1 << i) & x) > 0);
		if (r[i + 1]) tr++;
		c[i + 1] = (((1 << i) & y) > 0);
		if (c[i + 1]) tc++;
	}
	if (tr == n || tc == m) return 0;
	for (int i = 1; i <= n; i++) {
		if (r[i]) continue;
		top = 0;
		for (int j = 1; j <= m; j++) {
			if (c[j]) continue;
			c1[++top] = a[i][j];
		}
		if (top == 1) continue;
		if (c1[1] < c1[top]) {
			for (int j = 2; j <= top; j++) {
				if (c1[j] < c1[j - 1]) return 0;
			}
		}
		else {
			for (int j = 2; j <= top; j++) {
				if (c1[j] > c1[j - 1]) return 0;
			}
		}
	}
	top = 0;
	for (int i = 1; i <= m; i++) {
		if (c[i]) continue;
		top = 0;
		for (int j = 1; j <= n; j++) {
			if (r[j]) continue;
			r1[++top] = a[j][i];
		}
		if (top == 1) continue;
		if (r1[1] < r1[top]) {
			for (int j = 2; j <= top; j++) {
				if (r1[j] < r1[j - 1]) return 0;
			}
		}
		else {
			for (int j = 2; j <= top; j++) {
				if (r1[j] > r1[j - 1]) return 0;
			}
		}
	}
	return 1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i <= (1 << n) - 1; i++) {
		for (int j = 0; j <= (1 << m) - 1; j++) {
			if (check(i, j)) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
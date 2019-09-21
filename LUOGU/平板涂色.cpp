#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
int n, p, m, f[(1 << 17) + 10][22], ans = 0x7fffffff, tot, flag;
struct square {
	int x, y, _x, _y, col;
}s[MAXN];
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
bool check(int l, int x) {
	for (int i = 1; i <= p; i++) {
		if (s[i]._x <= s[x].x && ((s[i].y <= s[x]._y && s[i].y >= s[x].y) || (s[i]._y <= s[x]._y && s[i]._y >= s[x].y))) {
			if ((l & (1 << (i - 1))) == 0) return 0;
		}
	}
	return 1;
}
int main() {
	scanf("%d", &p);
	for (int i = 1; i <= p; i++) {
		scanf("%d%d%d%d%d", &s[i].x, &s[i].y, &s[i]._x, &s[i]._y, &s[i].col);
		n = max(n, s[i].col);
	}
	memset(f, 0x7f, sizeof(f));
	m = (1 << p) - 1;
	for (int i = 1; i <= n; i++) {
		f[0][i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		for (int k = 1; k <= p; k++) {
			if (i & (1 << (k - 1)) && check(i, k)) {
				flag = (i - (1 << (k - 1)));
				for (int j = 1; j <= n; j++) {
					if (j == s[k].col) f[i][s[k].col] = min(f[i][s[k].col], f[flag][j]);
					else f[i][s[k].col] = min(f[i][s[k].col], f[flag][j] + 1);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = min(ans, f[m][i]);
	}
	printf("%d\n", ans);
	return 0;
}
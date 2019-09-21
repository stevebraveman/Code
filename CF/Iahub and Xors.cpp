#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
int a[5][MAXN][MAXN], n, m;
int lowbit(int x) {
	return x & -x;
}
void cg(int x, int y, int k, int id) {
	for (int i = x; i <= n; i += lowbit(i)) {
		for (int j = y; j <= n; j += lowbit(j)) {
			a[id][i][j] ^= k;
			// printf("%d %d\n", i, j);
		}
	}
}
int ask(int x, int y, int id) {
	int ans = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		for (int j = y; j > 0; j -= lowbit(j)) {
			ans ^= a[id][i][j];
		}
	}
	return ans;
}
int g(int x, int y) {
	int rt = 0;
	if (x & 1) rt += 1;
	if (y & 1) rt += 2;
	return rt;
}
int op, x1, y1, x2, y2, k;
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			printf("%d\n", ask(x1 - 1, y1 - 1, g(x1 - 1, y1 - 1)) ^ ask(x2, y2, g(x2, y2)) ^ ask(x1 - 1, y2, g(x1 - 1, y2)) ^ ask(x2, y1 - 1, g(x2, y1 - 1)));
		}
		else {
			scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
			cg(x1, y1, k, g(x1, y1));
			cg(x2 + 1, y2 + 1, k, g(x2 + 1, y2 + 1));
			cg(x1, y2 + 1, k, g(x1, y2 + 1));
			cg(x2 + 1, y1, k, g(x2 + 1, y1));
		}
	}
}
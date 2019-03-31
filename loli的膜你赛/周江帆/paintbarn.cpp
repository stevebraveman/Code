#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#define lowbit(x) ((x)&(-(x)))
#define R register
#define ll long long
using namespace std;
inline void read(int &w) {
	int f = 1;
	w = 0;
	char s = getchar();
	while (s < '0' || s > '9') {if (s == '-') f = -1; s = getchar();}
	while ( s >= '0' && s <= '9') {w = w * 10 + s - '0'; s = getchar();}
	w *= f;
}
int n, m, k, tot;
struct BIT_2D {
	int a[4][1049][1049];
	void up(int x, int y, int d) {
		if (x < 1 || n < x || y < 1 || m < y) return;
		for (int i = x; i <= n; i += lowbit(i)) {
			for (int j = y; j <= m; j += lowbit(j)) {
				a[0][i][j] += d;
				a[1][i][j] += d * y;
				a[2][i][j] += d * x;
				a[3][i][j] += d * x * y;
				// a[0][i][j] += d;
			}
		}
	}
	int sum(int x, int y) {
		int res = 0;
		for (int i = x; i; i -= lowbit(i)) {
			for (int j = y; j; j -= lowbit(j)) {
				res = res + (x + 1) * (y + 1) * a[0][i][j] - (x + 1) * a[1][i][j] - (y + 1) * a[2][i][j] + a[3][i][j];
			}
		}
		return res;
	}
}tree;
int main() {
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
	scanf("%d%d", &n, &k);
	m = n;
	for (int i = 1, x1, y1, x2, y2; i <= n; i++) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1++, x2++, y1++, y2++;
		tree.up(x2, y2, 1);
		tree.up(x1 - 1, y2, -1);
		tree.up(x2, y1 - 1, -1);
		tree.up(x1 - 1, y1 - 1, 1);
	}
	for (int i = 1; i <= 11; i++) {
		for (int j = 1; j <= 11; j++) {
			int p = tree.sum(i, j) - tree.sum(i - 1, j) - tree.sum(i, j - 1) + tree.sum(i - 1, j - 1);
			printf("%d ", p);
			if (p == k) tot++;
		}
		puts("");
	}
	printf("%d", tot);
	return 0;
}

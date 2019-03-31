#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
#define MOD 2147483648LL
#define ll long long
ll a[MAXN][MAXN], pre[MAXN][MAXN], c[MAXN][MAXN], ans;
int n, m, w, x, y, k;
void prework() {
	c[1][1] = 1;
	for (int i = 2; i <= 1005; i++) {
		for (int j = 1; j <= 1005; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
}
int main() {
	freopen("religious.in", "r", stdin);
	freopen("religious.out", "w", stdout);
	prework();
	scanf("%d%d", &n, &m);
	scanf("%d", &w);
	for (int i = 1; i <= w; i++) {
		scanf("%d%d", &x, &y);
		x++;
		y++;
		a[x][y] = 1;
	}
	scanf("%d", &k);
	n++;
	m++;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pre[x][y] = pre[x][y - 1] + pre[x - 1][y] - pre[x - 1][y - 1] + a[x][y];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ll up = pre[i - 1][j] - pre[i - 1][j - 1];
			ll down = (pre[n][j] - pre[i + 1][j]) - (pre[n][j - 1] - pre[i][j - 1]);
			ll right = pre[i][j - 1] - pre[i - 1][j - 1];
			ll left = (pre[i][m] - pre[i][j + 1]) - (pre[i - 1][m] - pre[i - 1][j]);
			printf("%lld %lld %lld %lld\n", up, down, right, left);
			ans += c[up][k] * c[down][k] * c[right][k] * c[left][k];
		}
	}
	printf("%lld", ans);
	return 0;
}
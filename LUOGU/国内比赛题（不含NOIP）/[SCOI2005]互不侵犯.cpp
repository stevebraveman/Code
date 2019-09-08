#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
ll f[15][2000][100], s[2000], g[2000];
ll n, k, ans, cnt;
void dfs(ll l, ll num, ll nd) {
	if (nd >= n) {
		s[++cnt] = l;
		g[cnt] = num;
		return;
	}
	dfs(l, num, nd + 1);
	dfs(l + (1 << nd), num + 1, nd + 2);
}
int main() {
	scanf("%lld%lld", &n, &k);
	dfs(0, 0, 0);
	for (ll i = 1; i <= cnt; i++) {
		f[1][i][g[i]] = 1;
	}
	for (ll i = 2; i <= n; i++) {
		for (ll j = 1; j <= cnt; j++) {
			for (ll y = 1; y <= cnt; y++) {
				if (s[j] & s[y]) continue;
				if ((s[j] << 1) & s[y]) continue;
				if (s[j] & (s[y] << 1)) continue;
				for (ll p = k; p >= g[j]; p--) {
					f[i][j][p] += f[i - 1][y][p - g[j]];
				}
			}
		}
	}
	for (ll i = 1; i <= cnt; i++) {
		ans += f[n][i][k];
	}
	printf("%lld", ans);
	return 0;
}
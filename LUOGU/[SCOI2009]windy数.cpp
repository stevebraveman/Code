#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
int t;
ll dp[19][19];
ll l, r, k;
int shu[20];
ll dfs(int len, int l, bool zero, bool limit) {
	if (len == 0) return 1;
	if (!zero && !limit && dp[len][l])
		return dp[len][l];  //dp数组的内容应和dfs调用参数的内容相同，除了是否达到上限
	ll cnt = 0;
	int maxx = (limit ? shu[len] : 9);
	for (int i = 0; i <= maxx; i++) {
		if (zero || (int)abs(l - i) >= 2) cnt += dfs(len - 1, i, zero && i == 0, limit && i == shu[len]);
	}
	if (!limit && !zero)
		dp[len][l] = cnt;
	return cnt;
}

ll solve(ll x) {
	int k = 0;
	while (x) {
		shu[++k] = x % 10;
		x /= 10;
	}
	return dfs(k, 0, 1, 1);
}
int main() {
	memset(dp, 0, sizeof(dp));
	scanf("%lld%lld", &l, &r);
	printf("%lld\n", solve(r) - solve(l - 1));
	return 0;
}
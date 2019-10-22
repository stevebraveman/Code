#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 1010
std::vector<int> v[MAXN];
int x, n, m, k, ans;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &x);
			v[x].push_back(j);
		}
	}
	for (int i = 1; i <= k; i++) {
		std::sort(v[i].begin(), v[i].end());
	}
	for (int i = 1; i <= k; i++) {
		if (v[i].size()) ans = 1;
		else ans = 0;
		for (int j = 1; j < (int)v[i].size(); j++) {
			if (v[i][j] != v[i][j - 1]) {
				ans++;
			}
		}
		printf("%d ", ans);
	}
}
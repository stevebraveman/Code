//wdnmd
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAXN 1010
#define INF 2147483647
int tr[MAXN][3], f[MAXN], ed[MAXN], tot, d[MAXN][MAXN];
void insert(char *s) {
	int p = 0;
	for (int i = 0; s[i]; i++) {
		int k = s[i] - 'A';
		if (!tr[p][k]) tr[p][k] = ++tot;
		p = tr[p][k];
	}
	ed[p]++;
}
void build() {
	std::queue <int> q;
	for (int i = 0; i < 3; i++) {
		if (tr[0][i]) {
			q.push(tr[0][i]);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (tr[u][i]) {
				f[tr[u][i]] = tr[f[u]][i];
				q.push(tr[u][i]);
			}
			else tr[u][i] = tr[f[u]][i];
		}
		ed[u] += ed[f[u]];
	}
}
int dp(int k) {
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		for (int j = 1; j <= tot; j++) {
			d[i][j] = -INF;
		}
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= tot; j++) {
			for (int a = 0; a < 3; a++) {
				d[i][tr[j][a]] = std::max(d[i][tr[j][a]], d[i - 1][j] + ed[tr[j][a]]);
				// printf("%2d ", d[i][tr[j][a]]);
			}
		}
		// puts("");
	}
	// printf("%d\n", tot);
	for (int i = 0; i <= tot; i++) {
		// printf("%d\n", ans);
		ans = std::max(ans, d[k][i]);
	}
	return ans;
}
int n, k;
char s[MAXN];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		insert(s);
	}
	build();
	printf("%d", dp(k));
	return 0;
}
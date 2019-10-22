#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000100
int t[MAXN][26], ed[MAX], n, m, x, tot, f[MAXN], a[MAXN], dp[5010][5101];
char s[MAXN], s2[MAXN];
void insert(char *a) {
	int p = 0;
	for (int i = 0; a[i]; i++) {
		int k = a[i] - 'a';
		if (!t[p][k]) t[p][k] = ++tot;
		p = t[p][k];
	}
	ed[p] = 1;
}
void build() {
	std::queue <int> q;
	memset(f, 0, sizeof(f));
	for (int i = 0; i < 26; i++) {
		if (tr[0][i]) {
			q.push(tr[0][i]);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < 26; i++) {
			if (t[u][i]) {
				f[t[u][i]] = t[f[u]][i];
				q.push(t[u][i]);
			}
			else t[u][i] = t[f[u]][i];
		}
	}
}
void dp(char *s) {
	int p = 0;
	for (int i = 0; s[i]; i++) {
		int k = s[i] - 'a';
		p = tr[p][k];
		for (int j = p; j; j = f[j]) {
			dp[i][j] = dp[i][j]
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%s", s2);
		insert(s2);
	}
	dp(s);
}
/*
5 3
abcde
3 1 3 1 3
abc
bcd
cde
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#define MAXN 6000010
struct AC_auto {
	int t[MAXN][2], f[MAXN], tot;
	bool ed[MAXN], fl, vis[MAXN];
	void insert(char *s) {
		int p = 0;
		int l = strlen(s);
		for (int i = 0; i < l; i++) {
			int k = s[i] - '0';
			if (!t[p][k]) t[p][k] = ++tot;
			p = t[p][k];
		}
		ed[p] = 1;
	}
	void build() {
		std::queue <int> q;
		memset(f, 0, sizeof(f));
		for (int i = 0; i < 2; i++) {
			if (t[0][i]) {
				q.push(t[0][i]);
			}
		}
		while (!q.empty()) {
			int k = q.front();
			q.pop();
			for (int i = 0; i < 2; i++) {
				if (t[k][i]) {
					f[t[k][i]] = t[f[k]][i];
					ed[t[k][i]] |= ed[t[f[k]][i]];
					q.push(t[k][i]);
				}
				else t[k][i] = t[f[k]][i];
			}
		}
	}
	void dfs(int u) {
		if (vis[u]) {
			puts("TAK");
			exit(0);
		}
		vis[u] = 1;
		for (int i = 0; i < 2; i++) {
			int to = t[u][i];
			if (ed[to]) continue;
			dfs(to);
		}
		vis[u] = 0;
	}
}mch;
int n;
char s[114514];
int main() {
	scanf("%d", &n);
	mch.tot = 0;
	mch.fl = false;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		mch.insert(s);
	}
	mch.build();
	mch.dfs(0);
	puts("NIE");
	return 0;
}
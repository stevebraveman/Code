#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 1000010
int n, m, maxs;
char st[200][80], s[MAXN];
struct AC_Auto {
	int t[MAXN][26], f[MAXN], tot, ans[MAXN], e[MAXN];
	void insert(char *s, int kth) {
		int p = 0;
		int l = strlen(s);
		for (int i = 0; i < l; i++) {
			int k = s[i] - 'a';
			if (!t[p][k]) t[p][k] = ++tot;
			p = t[p][k];
		}
		e[p] = kth;
	}
	void build() {
		std::queue <int> q;
		memset(f, 0, sizeof(f));
		for (int i = 0; i < 26; i++) {
			if (t[0][i]) {
				q.push(t[0][i]);
			}
		}
		while (!q.empty()) {
			int k = q.front();
			q.pop();
			for (int i = 0; i < 26; i++) {
				if (t[k][i]) {
					f[t[k][i]] = t[f[k]][i];
					q.push(t[k][i]);
				}
				else t[k][i] = t[f[k]][i];
			}
		}
	}
	void find(char *s) {
		int p = 0;
		// int l = strlen(s);
		for (int i = 0; s[i]; i++) {
			p = t[p][s[i] - 'a'];
			for (int j = p; j; j = f[j]) {
				ans[e[j]]++;
			}
		}
	}
}mach;
int main() {
	while (1) {
		memset(mach.t, 0, sizeof(mach.t));
		memset(mach.e, 0, sizeof(mach.e));
		memset(mach.ans, 0, sizeof(mach.ans));
		memset(st, 0, sizeof(st));
		mach.tot = 0;
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			scanf("%s", st[i]);
			mach.insert(st[i], i);
		}
		mach.build();
		scanf("%s", s);
		mach.find(s);
		maxs = 0;
		for (int i = 1; i <= n; i++) {
			// printf("%d\n", mach.ans[i]);
			if (maxs < mach.ans[i]) {
				maxs = mach.ans[i];
			}
		}
		printf("%d\n", maxs);
		for (int i = 1; i <= n; i++) {
			if (maxs == mach.ans[i]) {
				puts(st[i]);
			}
		}
	}
}
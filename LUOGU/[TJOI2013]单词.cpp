#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 2010010
int n, m, maxs;
char st[MAXN], s[MAXN];
struct AC_Auto {
	struct Edge {
		int v, nx;
	}e[MAXN << 2];
	int t[MAXN][26], f[MAXN], tot, ans[MAXN], ed[MAXN], head[MAXN], ecnt;
	void insert(char *s, int kth) {
		int p = 0;
		int l = strlen(s);
		for (int i = 0; i < l; i++) {
			int k = s[i] - 'a';
			if (!t[p][k]) t[p][k] = ++tot;
			p = t[p][k];
			ans[p]++;
		}
		ed[kth] = p;
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
	void add(int f, int t) {
		e[++ecnt] = (Edge) {t, head[f]};
		head[f] = ecnt;
	}
	void dfs(int u) {
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			dfs(to);
			ans[u] += ans[to];
		}
	}
	void makegraph() {
		for (int i = 1; i <= tot; i++) {
			add(f[i], i);
		}
	}
}mach;
int main() {
	memset(st, 0, sizeof(st));
	mach.tot = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", st);
		mach.insert(st, i);
	}
	mach.build();
	mach.makegraph();
	mach.dfs(0);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", mach.ans[mach.ed[i]]);
	}
}
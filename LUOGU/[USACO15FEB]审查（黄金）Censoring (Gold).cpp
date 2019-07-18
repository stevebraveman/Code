#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000010
char s[MAXN], s2[MAXN];
int n;
struct AC_Auto {
	int t[MAXN][26], f[MAXN], tot, st[MAXN], st2[MAXN], e[MAXN], top;
	void insert(char *s) {
		int p = 0;
		int l = strlen(s);
		for (int i = 0; i < l; i++) {
			int k = s[i] - 'a';
			if (!t[p][k]) t[p][k] = ++tot;
			p = t[p][k];
		}
		e[p] = l;
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
		int l = strlen(s);
		for (int i = 0; i < l; i++) {
			p = t[p][s[i] - 'a'];
			st[++top] = p;
			st2[top] = i;
			if (e[p]) {
				top -= e[p];
				if(!top) p = 0;
				else p = st[top];
			}
		}
	}
}mach;
int main() {
	scanf("%s", s);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s2);
		mach.insert(s2);
	}
	mach.build();
	mach.find(s);
	for (int i = 1; i <= mach.top; i++) {
		std::cout << s[mach.st2[i]];
	}
	puts("");
	return 0;
}
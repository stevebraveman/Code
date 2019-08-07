#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 10000100
int tr[MAXN][4], f[MAXN], ed[MAXN], tot, len[MAXN], ans[100011];
bool us[MAXN];
int z(char a) {
	if (a == 'E') return 0;
	if (a == 'S') return 1;
	if (a == 'W') return 2;
	if (a == 'N') return 3;
}
void insert(char *s, int kth) {
	int p = 0;
	for (int i = 0; s[i]; i++) {
		int k = z(s[i]);
		if (!tr[p][k]) tr[p][k] = ++tot;
		p = tr[p][k];
	}
	ed[p] = kth;
}
void build() {
	std::queue <int> q;
	memset(f, 0, sizeof(f));
	for (int i = 0; i < 4; i++) {
		if (tr[0][i]) {
			q.push(tr[0][i]);
		}
	}
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (tr[k][i]) {
				f[tr[k][i]] = tr[f[k]][i];
				q.push(tr[k][i]);
			}
			else tr[k][i] = tr[f[k]][i];
		}
	}
}
void find(char *s) {
	int p = 0;
	for (int i = 0; s[i]; i++) {
		p = tr[p][z(s[i])];
		for (int j = p; j; j = f[j]) {
			if (us[j]) break;
			us[j] = 1;
		}
	}
}
int n, m;
char s1[100010][101], s2[MAXN];
int solve(char *s) {
	int p = 0, res = 0;
	for (int i = 0; s[i]; i++) {
		p = tr[p][z(s[i])];
		if (us[p]) res = i + 1;
	}
	return res;
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s2);
	for (int i = 1; i <= m; i++) {
		scanf("%s", s1[i]);
		insert(s1[i], i);
	}
	build();
	find(s2);
	for (int i = 1; i <= m; i++) {
		printf("%d\n", solve(s1[i]));
	}
}
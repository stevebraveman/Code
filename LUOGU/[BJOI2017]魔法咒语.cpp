#include <iostream>
#include <cstdio>
#include <algorithm>
#include <algorithm>
#define MAXN 101010
int t[MAXN][26], f[MAXN], n, m, x, y, ed[MAXN], tot, l;
void insert(char *s) {
	int p = 0;
	for (int i = 0; s[i]; i++) {
		int k = s[i] - 'a';
		if (!t[p][k]) t[p][k] = ++tot;
		p = t[p][k];
	}
	ed[p] = 1;
}
void build() {
	memset(f, 0, sizeof(f));
	std::queue <int> q;
	for (int i = 0; i < 26; i++) {
		if (t[0][i]) {
			q.push(t[0][i]);
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
void dp() {

}
int main() {

}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 100010
std::vector <int> ed[MAXN];
int tr[MAXN][26], n, m, f[MAXN], tot;
void insert(char *s, int l, int r, int pos) {
	int p = 0;
	for (int i = l; i <= r; i++) {
		int k = tr[i][s[i] - 'a'];
		if (!tr[i][k]) tr[i][k] = ++tot;
		p = tr[i][k];
	}
	ed[p].push_back(pos);
}
void build() {
	std::queue <int> q;
	for (int i = 0; i < 26; i++) {
		if (tr[0][i]) {
			q.push(tr[0][i]);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < 26; i++) {
			if (tr[u][i]) {
				f[tr[u][i]] = tr[f[u]][i];
				q.push(tr[u][i]);
			}
			else tr[u][i] = tr[f[u]][i];
		}
	}
}
bool find(char *s) {
	int p = 0;
}
char s[MAXN];
int main() {
	
}
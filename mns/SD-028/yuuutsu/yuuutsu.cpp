#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAXN 100010
int p[MAXN + 10], chk[MAXN + 10], tot, pre[MAXN], jc[21][21];
int T, x, y;
struct node {
	int id, p;
};
std::vector<node> v[MAXN];
void seive(int lim) {
	for (int i = 2; i <= lim; i++) {
		if (!chk[i]) {
			p[++tot] = i;
		}
		for (int j = 1; j <= tot && i * p[j] <= lim; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				break;
			}
		}
	}
	for (int i = 1; i <= lim; i++) {
		int k = i;
		for (int j = 1; j <= tot && p[j] * p[j] <= i; j++) {
			if (k == 1) break;
			node f;
			f.id = f.p = 0;
			while (k % p[j]) {
				k /= p[j];
				f.p++;
			}
			f.id = p[j];
			v[i].push_back(f);
		}
		if (k != 1) v[i].push_back((node) {k, 1});
	}
}
int main() {
	freopen("yuuutsu.in", "r", stdin);
	freopen("yuuutsu.out", "w", stdout);
	pre[0] = 1;
	for (int i = 1; i <= 10; i++) {
		pre[i] = pre[i - 1] * i;
	}
	for (int i = 1; i <= 10; i++) {
		jc[i][0] = 1;
		for (int j = 1; j <= 10; j++) {
			jc[i][j] = jc[i][j - 1] * i;
		}
	}
	scanf("%d\n", &T);
	while (T--) {
		scanf("%d%d", &x, &y);
		puts(jc[x][y] <= pre[y] ? "Yes" : "No");
	}
	return 0;
}
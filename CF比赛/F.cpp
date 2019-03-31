#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 150060
std::vector <int> v[MAXN];
int x[MAXN], y[MAXN], n, r, a[MAXN], cnt;
void dfs(int x, int fa) {
	a[++cnt] = x;
	for (int i = 0; i < (int)v[x].size(); i++) {
		int to = v[x][i];
		if (to == fa) continue;
		dfs(to, x);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		v[x[i]].push_back(y[i]);
		v[y[i]].push_back(x[i]);
	}
	for (int i = 1; i < n; i++) {
		if (v[x[i]].size() == 1) {
			r = i;
			break;
		}
		else if (v[y[i]].size() == 1) {
			r = i;
			break;
		}
	}
	dfs(r, 0);
	for (int i = 1; i <= cnt; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
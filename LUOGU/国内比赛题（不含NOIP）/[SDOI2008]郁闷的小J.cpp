#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <tr1/unordered_map>
using namespace std;
#define MAXN 100005
tr1::unordered_map<int, int> h;
int n, m, sq, tag[318][200002], b[MAXN], a[MAXN], cnt, x, y, z;
char op[5];
void update(int u, int v) {
	if (!h[u]) h[u] = ++cnt;
	tag[b[v]][h[a[v]]]--;
	tag[b[v]][h[u]]++;
	a[v] = u;
}
int ask(int l, int r, int k) {
	int ans = 0;
	if (!h[k]) return 0;
	for (int i = l; i <= min(r, b[l] * sq); i++) {
		if (a[i] == k) ans++;
	}
	if (b[l] != b[r]) {
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			if (a[i] == k) ans++;
		}
	}
	int t = h[k];
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		ans += tag[i][t];
	}
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (!h[a[i]]) {
			h[a[i]] = ++cnt;
		}
		b[i] = (i - 1) / sq + 1;
	}
	for (int i = 1; i <= n; i++) {
		tag[b[i]][h[a[i]]]++;
	}
	while (m--) {
		scanf("%s", op);
		if (op[0] == 'Q') {
			scanf("%d%d%d", &x, &y, &z);
			printf("%d\n", ask(x, y, z));
		}
		else {
			scanf("%d%d", &x, &y);
			update(y, x);
		}
	}
}
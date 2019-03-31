#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MAXN 100010
int n, m, a[MAXN], preh[MAXN], preg[MAXN], ans = 0, l, r, k, cnt, gg, hh;
char p[MAXN];
bool check(int l, int r) {
	int x = preh[r] - preh[l - 1];
	int y = preg[r] - preg[r - 1];
	return x <= y;
}
int main() {
	freopen("redistricting.in", "r", stdin);
	freopen("redistricting.out", "w", stdout);
	scanf("%d%d", &n, &k);
	scanf("%s", p + 1);
	for (int i = 1; i <= n + k; i++) {
		if (p[i] == 'H') preh[i] = preh[i - 1] + 1, preg[i] = preg[i - 1];
		else preg[i] = preg[i - 1] + 1, preh[i] = preh[i - 1];
	}
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			if (p[i] == 'G') {
				cnt++;
			}
		}
		printf("%d", cnt);
		return 0;
	}
	for (int i = 1; i <= n; ) {
		if (p[i] == 'H') i++;
		else {
			gg = preg[i + k - 1] - preg[i - 1];
			hh = preh[i + k - 1] - preh[i - 1];
			if (gg > hh) {
				l = i - 1;
				r = i + k - 1;
				m = 0;
				while (l <= r) {
					m = (l + r) >> 1;
					if (check(l, r)) l = m + 1;
					else r = m;
				}
				i = l;
				ans++;
			}
			else {
				i = i + k;
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
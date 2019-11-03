#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 1010
int a[MAXN][MAXN], ans[MAXN], n, tot = 1, T, m, po[MAXN];
char s[MAXN];
std::vector <int> v;
int main() {
	scanf("%d\n", &T);
	po[0] = 1;
	for (int i = 1; i <= 8; i++) {
		po[i] = po[i - 1] * 2;
	}
	while (T--) {
		scanf("%d%d", &n, &m);
		// for (int i = 1; i <= m; i++) {
		// 	v[i].clear();
		// }
		std::sort(po + 1, po + 1 + m);
		for (int i = 1; i <= n; i++) {
			scanf("%s", s + 1);
			for (int j = 1; j <= m; j++) {
				if (s[j] == 'Y') {
					a[i][j] = 1;
				}
				else {
					a[i][j] = 0;
				}
			}
		}
		int tmax = 0, maxa = 0, maxh = 0, tmaxh = 0;
		bool flag = 1;
		do {
			// puts("OK");
			tmax = 0, maxa = 0, maxh = 0, tmaxh = 0;
			for (int i = 1; i <= n; i++) {
				ans[i] = 0;
				for (int j = 1; j <= m; j++) {
					if (a[i][j]) {
						ans[i] += po[j];
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				if (maxh <= ans[i]) {
					maxh = ans[i];
					maxa = i;
					// v.push_back(i);
				}
			}
			for (int i = 1; i <= n; i++) {
				if (ans[i] < maxh && ans[i] > tmaxh) {
					tmaxh = ans[i];
					tmax = i;
				}
			}
			if (tmax == 1) {
				flag = 0;
				break;
			}
			// v.clear();
		} while (std::next_permutation(po + 1, po + 1 + m));
		// printf("%d %d %d %d\n", tmax, maxa, maxh, tmaxh);
		if (!flag) {
			puts("YES");
		}
		else  puts("NO");
		// for (int i = 1; i <= m; i++) {
		// 	for (int j = 0; j < (int)v[i].size(); j++) {
		// 		printf("%d ", v[i][j]);
		// 	}
		// 	puts("");
		// }
	}
}
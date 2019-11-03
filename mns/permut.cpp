#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 5010
#define INF 0x7fffffff
int a[MAXN], n, b[MAXN], c[MAXN], d[MAXN], k, ans, st[MAXN], fin[MAXN];
bool vis[MAXN];
std::vector <int> v[MAXN];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		c[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		d[i] = b[i];
		st[i] = i;
	}
	std::sort(c + 1, c + 1 + n);
	std::sort(d + 1, d + 1 + n);
	k = 1;
	bool fl = 0;
	for (int i = 1; i <= n; i++) {
		if (k > n) break;
		while (c[i] >= d[k]) {
			k++;
			if (k > n) {
				fl = 1;
				break;
			}
		}
		if (fl) break;
		ans++;
	}
	do {
		int tot = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] < b[st[i]]) tot++;
		}
		if (tot == ans) {
			int i;
			for (i = 1; i <= n; i++) {
				if (st[i] != b[i]) {
					break
				}
			}
			for (i; i <= n; i++) {

			}
		}
	} while (next_permutation(st + 1, st + 1 + n));
}
/*
10 
3 9 7 4 6 9 1 4 6 8
1 10 7 7 7 1 7 1 9 4

10 1 9 7 7 1 4 7 7 1
 */
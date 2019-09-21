#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define MAXN 100010
#define re register
int a[MAXN], b[MAXN], tag[MAXN], n, m, sq, cnt, num[320][MAXN], hs[MAXN], zx, last = 0, p, f[320][320], st[MAXN], top;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void init() {
	int ans = 0;
	for (re int i = 1; i <= b[n]; i++) {
		ans = 0;
		for (re int j = (i - 1) * sq + 1; j <= n; j++) {
			num[i][a[j]]++;
			if ((num[i][a[j]] & 1) && (num[i][a[j]] > 1)) {
				ans--;
			}
			else if (!(num[i][a[j]] & 1)) {
				ans++;
			}
			if (b[j] != b[j + 1]) f[i][b[j]] = ans;
		}
	}
}
void swap(int &x, int &y) {
	int t = x;
	x = y;
	y = t;
}
int query(int l, int r) {
	int ans = 0, gg;
	memset(tag, 0, sizeof(tag));
	top = 0;
	if (b[l] == b[r]) {
		for (re int i = l; i <= r; i++) {
			tag[a[i]]++;
			st[++top] = a[i];
		}
		while (top) {
			gg = st[top];
			if (tag[gg]) {
				ans += (tag[gg] & 1) ^ 1;
				tag[gg] = 0;
			}
			top--;
		}
		return ans;
	}
	if (b[l] != b[r]) {
		ans = f[b[l] + 1][b[r] - 1];
		for (re int i = l; i <= min(b[l] * sq, r); i++) {
			tag[a[i]]++;
			st[++top] = a[i];
		}
		for (re int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			tag[a[i]]++;
			st[++top] = a[i];
		}
		while (top) {
			gg = st[top];
			if (tag[gg]) {
				if (num[b[l] + 1][gg] - num[b[r]][gg] > 0) {
					if ((tag[gg] & 1) && !((num[b[l] + 1][gg] - num[b[r]][gg]) & 1)) {
						ans--;
					}
					else if ((tag[gg] & 1) && ((num[b[l] + 1][gg] - num[b[r]][gg]) & 1)) {
						ans++;
					}
				}
				else {
					if (!(tag[gg] & 1)) {
						ans++;
					}
				}
				tag[gg] = 0;
			}
			top--;
		}
	}
	return ans;
}
int main() {
	scanf("%d%d%d", &n, &p, &m);
	for (re int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sq = sqrt(n);
	for (re int i = 1; i <= n; i++) {
		b[i] = (i - 1) / sq + 1;
	}
	init();
	for (re int i = 1, x, y; i <= m; i++) {
		scanf("%d%d", &x, &y);
		x = (last + x) % n + 1, y = (last + y) % n + 1;
		if (x > y) {
			swap(x, y);
		}
		last = query(x, y);
		printf("%d\n", last);
	}
}
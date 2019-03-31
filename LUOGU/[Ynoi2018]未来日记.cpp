#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
bool p1;
int a[MAXN], fa[MAXN], b[MAXN], n, sq, c[MAXN][501], d[MAXN][501], op, m;
int ra[501][400], maxx = 0, ro[MAXN][501], rk[MAXN], bn[MAXN], tmp[MAXN], tmp1[MAXN];
bool p2;
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void un(int p) {
	for (int i = (p - 1) * sq + 1; i <= min(n, sq * p); i++) {
		if (!ro[a[i]][p]) ro[a[i]][p] = i;
		else fa[i] = ro[a[i]][p];
	}
}
void change(int l ,int r, int x, int y) {
	int tot = 0;
	ro[x][b[l]] = ro[y][b[l]] = 0;
	for (int i = (b[l] - 1) * sq + 1; i <= min(sq * b[l], r); i++) {
		if (a[i] == x || a[i] == y) {
			fa[i] = i;
		}
	}
	for (int i = (b[l] - 1) * sq + 1; i <= min(sq * b[l], r); i++) {
		a[i] = a[find(i)];
		if (a[i] == x || a[i] == y) {
			if (!ro[a[i]][b[l]]) {
				ro[a[i]][b[l]] = a[i];
			} else {
				fa[i] = ro[a[i]][b[l]];
			}
		}
	}
	for (int i = l; i <= min(sq * b[l], r); i++) {
		if (a[i] == x) a[i] = y, tot++;
	}
	c[x][b[l]] -= tot;
	c[y][b[l]] += tot;
	for (int i = b[l]; i <= b[n]; i++) {
		d[x][i] -= tot;
		d[y][i] += tot;
		if (bn[x] != bn[y]) {
			ra[bn[x]][i] -= tot;
			ra[bn[y]][i] += tot;
		}
	}
	if (b[l] != b[r]) {
		tot = 0;
		ro[x][b[l]] = ro[y][b[l]] = 0;
		for (int i = (b[r] - 1) * sq + 1; i <= min(sq * b[r], n); i++) {
			if (a[i] == x || a[i] == y) {
				fa[i] = i;
			}
		}
		for (int i = (b[r] - 1) * sq + 1; i <= min(sq * b[r], n); i++) {
			a[i] = a[find(i)];
			if (a[i] == x || a[i] == y) {
				if (!ro[a[i]][b[r]]) {
					ro[a[i]][b[r]] = a[i];
				} else {
					fa[i] = ro[a[i]][b[r]];
				}
			}
		}
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			if (a[i] == x) a[i] = y, tot++;
		}
		c[x][b[r]] -= tot;
		c[y][b[r]] += tot;
		for (int i = b[r]; i <= b[n]; i++) {
			d[x][i] -= tot;
			d[y][i] += tot;
			if (bn[x] != bn[y]) {
				ra[bn[x]][i] -= tot;
				ra[bn[y]][i] += tot;
			}
		}
	}
	tot = 0;
	int ktot = 0;
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		if (ro[i][x]) {
			if (!ro[i][y]) ro[i][y] = ro[i][x], a[ro[i][y]] = y;
			else fa[ro[i][x]] = ro[i][y];
			ro[i][x] = 0;
			tot = c[i][x];
			ktot += tot;
			c[i][y] += c[i][x];
			c[i][x] = 0;
		}
		d[i][x] -= ktot;
		d[i][y] += ktot;
		if (bn[x] != bn[y]) {
			ra[bn[x]][i] -= ktot;
			ra[bn[y]][i] += ktot;
		}
	}
}
int ask(int l, int r, int k) {
	int tot = 0, ans = 0;
	for (int i = l; i <= min(b[l] * sq, r); i++) {
		a[i] = a[find(i)];
		tmp[a[i]]++;
		tmp1[bn[a[i]]]++;
	}
	int _l = 1, _r = -1;
	for (int i = 1; i <= bn[100000]; i++) {
		tot += tmp1[i];
		if (tot >= k) {
			tot -= tmp1[i];
			_l = (i - 1) * 320 + 1;
			_r = i * 320;
			break;
		}
	}
	// printf("%d %d\n", _l, _r);
	for (int i = _l; i <= _r; i++) {
		tot += tmp[i];
		if (tot >= k) {
			ans = i;
			break;
		}
	}
	// puts("OK");
	if (b[l] != b[r]) {
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			a[i] = a[find(i)];
			tmp[a[i]]++;
			tmp1[bn[a[i]]]++;
		}
		for (int i = 1; i <= bn[100000]; i++) {
			tot += tmp1[i] + ra[i][b[r] - 1] - ra[i][b[l]];
			if (tot >= k) {
				tot -= tmp1[i] + ra[i][b[r] - 1] - ra[i][b[l]];
				_l = (i - 1) * 320 + 1;
				_r = i * 320;
				break;
			}
		}
		for (int i = _l; i <= _r; i++) {
			tot += tmp[i] + d[i][b[r] - 1] - d[i][b[l]];
			if (tot >= k) {
				ans = i;
				break;
			}
		}
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			tmp[a[i]]--;
			tmp1[bn[a[i]]]--;
		}
	}
	for (int i = l; i <= min(b[l] * sq, r); i++) {
		tmp[a[i]]--;
		tmp1[bn[a[i]]]--;
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	printf("%.2f MB\n", (double)(&p2 - &p1) / 1024 / 1024);
#endif
	scanf("%d%d", &n, &m);
	sq = 500;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = (i - 1) / sq + 1;
	}
	for (int i = 1; i <= 100000; i++) {
		bn[i] = (i - 1) / 320 + 1;
	}
	for (int i = 1; i <= n; i++) {
		c[a[i]][b[i]]++;
	}
	for (int i = 1; i <= b[n]; i++) {
		un(i);
		for (int j = 1; j <= 100000; j++) {
			d[j][i] = d[j][i - 1] + c[j][i];
		}
		for (int j = 1; j <= 320; j++) {
			ra[j][i] = ra[j][i - 1];
		}
		for (int j = (i - 1) * sq + 1; j <= min(i * sq, n); j++) {
			ra[i][bn[a[j]]]++;
		}
	}
	for (int i = 1, l, r, x, y, k; i <= m; i++) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d%d", &l, &r, &x, &y);
			if (x == y) continue;
			change(l , r, x, y);
		} else {
			scanf("%d%d%d", &l ,&r, &k);
			printf("%d\n", ask(l, r, k));
		}
	}
}
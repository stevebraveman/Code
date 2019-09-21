#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define blz 320
bool p1;
int a[MAXN], fa[MAXN], b[MAXN], n, sq, c[180][MAXN], d[180][MAXN], op, m, st[MAXN], maxv;
int ra[180][400], maxx = 0, ro[180][MAXN], rk[MAXN], bn[MAXN], tmp[MAXN], tmp1[MAXN];
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
		if (!ro[p][a[i]]) ro[p][a[i]] = i;
		else fa[i] = ro[p][a[i]];
	}
}
void change(int l ,int r, int x, int y) {
	int tot = 0, top = 0;
	ro[b[l]][x] = ro[b[l]][y] = 0;
	for (int i = (b[l] - 1) * sq + 1; i <= min(sq * b[l], n); i++) {
		a[i] = a[find(i)];
		if (a[i] == x || a[i] == y) {
			st[++top] = i;
		}
	}
	for (int i = l; i <= min(sq * b[l], r); i++) {
		if (a[i] == x) a[i] = y, tot++;
	}
	for (int i = 1; i <= top; i++) {
		fa[st[i]] = st[i];
	}
	for (int i = 1; i <= top; i++) {
		if (!ro[b[l]][a[st[i]]]) {
			ro[b[l]][a[st[i]]] = st[i];
		}
		else {
			fa[st[i]] = ro[b[l]][a[st[i]]];
		}
	}
	c[b[l]][x] -= tot;
	c[b[l]][y] += tot;
	for (int i = b[l]; i <= b[n]; i++) {
		d[i][x] -= tot;
		d[i][y] += tot;
		if (bn[x] != bn[y]) {
			ra[i][bn[x]] -= tot;
			ra[i][bn[y]] += tot;
		}
	}
	if (b[l] != b[r]) {
		tot = 0, top = 0;
		ro[b[r]][x] = ro[b[r]][y] = 0;
		for (int i = (b[r] - 1) * sq + 1; i <= min(sq * b[r], n); i++) {
			a[i] = a[find(i)];
			if (a[i] == x || a[i] == y) {
				st[++top] = i;
			}
		}
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			if (a[i] == x) a[i] = y, tot++;
		}
		for (int i = 1; i <= top; i++) {
			fa[st[i]] = st[i];
		}
		for (int i = 1; i <= top; i++) {
			if (!ro[b[r]][a[st[i]]]) {
				ro[b[r]][a[st[i]]] = st[i];
			}
			else {
				fa[st[i]] = ro[b[r]][a[st[i]]];
			}
		}
		c[b[r]][x] -= tot;
		c[b[r]][y] += tot;
		for (int i = b[r]; i <= b[n]; i++) {
			d[i][x] -= tot;
			d[i][y] += tot;
			if (bn[x] != bn[y]) {
				ra[i][bn[x]] -= tot;
				ra[i][bn[y]] += tot;
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
			c[i][x] = 0;
			c[i][y] += tot;
		}
		d[i][x] -= ktot;
		d[i][y] += ktot;
		if (bn[x] != bn[y]) {
			ra[i][bn[x]] -= ktot;
			ra[i][bn[y]] += ktot;
		}
	}
	if (ktot) {
		for (int i = b[r]; i <= b[n]; i++) {
			d[i][x] -= ktot;
			d[i][y] += ktot;
			if (bn[x] != bn[y]) {
				ra[i][bn[x]] -= ktot;
				ra[i][bn[y]] += ktot;
			}
		}
	}
}
int ask(int l, int r, int k) {
	int tot = 0, ans = 0, _l = 1, _r = -1;
	if (b[l] == b[r]) {
		for (int i = l; i <= r; i++) {
			a[i] = a[find(i)];
			tmp[a[i]]++;
			tmp1[bn[a[i]]]++;
		}
		for (int i = 1; i <= bn[maxv]; i++) {
			tot += tmp1[i];
			if (tot >= k) {
				tot -= tmp1[i];
				_l = (i - 1) * blz + 1;
				_r = i * blz;
				break;
			}
		}
		for (int i = _l; i <= _r; i++) {
			tot += tmp[i];
			if (tot >= k) {
				ans = i;
				break;
			}
		}
		for (int i = l; i <= min(b[l] * sq, r); i++) {
			tmp[a[i]]--;
			tmp1[bn[a[i]]]--;
		}
	}
	else {
		tot = 0;
		for (int i = l; i <= b[l] * sq; i++) {
			a[i] = a[find(i)];
			tmp[a[i]]++;
			tmp1[bn[a[i]]]++;
		}
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			a[i] = a[find(i)];
			tmp[a[i]]++;
			tmp1[bn[a[i]]]++;
		}
		for (int i = 1; i <= bn[maxv]; i++) {
			tot += tmp1[i] + ra[b[r] - 1][i] - ra[b[l]][i];
			if (tot >= k) {
				tot -= tmp1[i] + ra[b[r] - 1][i] - ra[b[l]][i];
				_l = (i - 1) * blz + 1;
				_r = i * blz;
				break;
			}
		}
		for (int i = _l; i <= _r; i++) {
			tot += tmp[i] + d[b[r] - 1][i] - d[b[l]][i];
			if (tot >= k) {
				ans = i;
				break;
			}
		}
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			tmp[a[i]]--;
			tmp1[bn[a[i]]]--;
		}
		for (int i = l; i <= b[l] * sq; i++) {
			tmp[a[i]]--;
			tmp1[bn[a[i]]]--;
		}
	}
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	sq = 600;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		maxv = max(a[i], maxv);
		fa[i] = i;
		b[i] = (i - 1) / sq + 1;
	}
	for (int i = 1; i <= maxv; i++) {
		bn[i] = (i - 1) / blz + 1;
	}
	for (int i = 1; i <= n; i++) {
		c[b[i]][a[i]]++;
	}
	for (int i = 1; i <= b[n]; i++) {
		un(i);
		for (int j = 1; j <= maxv; j++) {
			d[i][j] = d[i - 1][j] + c[i][j];
		}
		for (int j = 1; j <= blz; j++) {
			ra[i][j] = ra[i - 1][j];
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
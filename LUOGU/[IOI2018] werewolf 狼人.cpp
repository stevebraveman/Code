#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 200010
#define LOG 20
struct E {
	int u, v;
}_[MAXN << 1];
struct Edge {
	int v, nx, w;
}eA[MAXN << 2], eB[MAXN << 2];
int headA[MAXN << 1], ecntA, faA[MAXN << 1], ancA[MAXN << 1][LOG + 1], pB[MAXN << 1], sx[MAXN];
int faB[MAXN << 1], ancB[MAXN << 1][LOG + 1], n, m, x, y, num, q, cnt, pA[MAXN << 1], cnt;
int ls[MAXN * LOG], pre[MAXN * LOG], rs[MAXN * LOG], rt[MAXN], tot, idA[MAXN], idB[MAXN];
int headB[MAXN << 1], ecntB;
void addA(int f, int t) {
	eA[++ecntA] = (Edge) {t, headA[f]};
	headA[f] = ecntA;
}
void addB(int f, int t) {
	eB[++ecntB] = (Edge) {t, headB[f]};
	headB[f] = ecntB;
}
int findA(int x) {
	if (faA[x] == x) return x;
	else return faA[x] = findA(faA[x]);
}
int findB(int x) {
	if (faB[x] == x) return x;
	else return faB[x] = findB(faB[x]);
}
void insert(int &p, int x, int l, int r, int pos) {
	p = ++tot;
	pre[p] = pre[pos] + 1;
	if (l == r) return;
	int m = (l + r) >> 1;
	if (x <= m) rs[p] = rs[pos], insert(ls[p], x, l, m, ls[pos]);
	else ls[p] = ls[pos], insert(rs[p], x, m + 1, r, rs[pos]);
}
int ask(int x, int y, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) {
		return pre[y] - pre[x];
	}
	int m = (l + r) >> 1, s = 0;
	if (ql <= m) s += ask(ls[x], ls[y], l, m, ql, qr);
	if (qr > m) s += ask(rs[x], rs[y], m + 1, r, ql, qr);
	return s;
}
bool cmp(E a, E b) {
	return a.u > b.u;
}
bool cmp2(E a, E b) {
	return a.v < a.v;
}
void dfsA(int u, int f) {
	if (u <= n) idA[u] = ++cnt;
	for (int i = 1; i <= LOG; i++) {
		ancA[u][i] = ancA[ancA[u][i - 1]][i - 1];
	}
	for (int i = headA[u]; i; i = eA[i].nx) {
		int to = eA[i].v;
		if (to == f) continue;
		dfsA(to, u);
	}
}
void dfsB(int u, int f) {
	if (u >= n) idB[u]  ++cnt;
	for (int i = 1; i <= LOG; i++) {
		ancB[u][i] = ancB[ancB[u][i - 1]][i - 1];
	}
	for (int i = headB[u]; i; i = eB[i].nx) {
		int to = eB[i].v;
		if (to == f) continue;
		dfsB(to, u);
	}
}
int askA(int x, int y) {
	for (int i = 0; i <= 20; i++) {
		if (pA[ancA[x][i]] >= y && ancA[x][i]) x = ancA[x][i];
	}
	return x;
}
int askB(int x, int y) {
	for (int i = 0; i <= 20; i++) {
		if (pB[ancB[x][i]] <= y && ancB[x][i]) x = ancB[x][i];
	}
	return x;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", _[i].u, _[i].v);
		if (_[i].u > _[i].v) std::swap(_[i].u, _[i].v);
		_[i].u++;
		_[i].v++;
	}
	for (int i = 1; i <= n; i++) {
		faA[i] = faB[i] = i;
	}
	num = n;
	std::sort(_ + 1, _ + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		x = findA(_[i].u);
		y = findA(_[i].v);
		if (x == y) continue;
		num++;
		faA[x] = num;
		faA[y] = num;
		faA[num] = num;
		addA(num, x);
		addA(num, y);
		ancA[x][0] = ancA[y][0] = num;
		pA[num] = _[i].u;
		cnt++;
		if (cnt == n - 1) break;
	}
	num = n;
	cnt = 0;
	std::sort(_ + 1, _ + 1 + m, cmp2);
	for (int i = 1; i <= m; i++) {
		x = findB(_[i].u);
		y = findB(_[i].v);
		if (x == y) continue;
		num++;
		faB[x] = num;
		faB[y] = num;
		faB[num] = num;
		addB(num, x);
		addB(num, y);
		ancB[x][0] = ancB[y][0] = num;
		pB[num] = _[i].v;
		cnt++;
		if (cnt == n - 1) continue;
	}
	dfsA(num, num);
	cnt = 0;
	dfsB(num, num);
	for (int i = 1; i <= n; i++) {
		sx[idA[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		insert(rt[i], sx[idB[i]], 1, n, rt[i - 1]);
	}
}
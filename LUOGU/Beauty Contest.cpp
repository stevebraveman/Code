#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100010
#define sqr(x) ((x) * (x))
#define ll long long
struct pt {
	ll x, y;
}p[MAXN], st[MAXN], p0;
ll crossp(pt a, pt b, pt c) {
	ll x1 = a.x - c.x;
	ll y1 = a.y - c.y;
	ll x2 = b.x - c.x;
	ll y2 = b.y - c.y;
	return x1 * y2 - y1 * x2;
}
ll dis(pt a, pt b) {
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}
bool cmp(pt a, pt b) {
	if (atan2(a.y - p0.y, a.x - p0.x) != atan2(b.y - p0.y, b.x - p0.x)) {
		return atan2(a.y - p0.y, a.x - p0.x) < atan2(b.y - p0.y, b.x - p0.x);
	}
	else return a.x < b.x;
}
template <typename T>
void sw(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}
int n, top, f, r;
ll ans, tmp;
int main() {
	scanf("%d", &n);
	p0.x = 5000000;
	p0.y = 5000000;
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &p[i].x, &p[i].y);
		if (p[i].y < p0.y || ((p[i].y == p0.y) && p[i].x < p0.x)) p0 = p[i], r = i;
	}
	sw(p[r], p[1]);
	std::sort(p + 2, p + n + 1, cmp);
	st[1] = p[1];
	st[2] = p[2];
	top = 2;
	n++;
	p[n] = p[1];
	for (int i = 3; i <= n; i++) {
		while (top > 1 && crossp(st[top - 1], p[i], st[top]) >= 0) top--;
		st[++top] = p[i];
	}
	st[top + 1] = st[1];
	f = 3;
	for (int i = 1; i <= top; i++) {
		while (fabs(crossp(st[i], st[i + 1], st[f])) < fabs(crossp(st[i], st[i + 1], st[f + 1]))) {
			f++;
			if (f > top) f = 1;
		}
		tmp = std::max(dis(st[i], st[f]), dis(st[i + 1], st[f]));
		ans = std::max(ans, tmp);
	}
	printf("%lld\n", ans);
	return 0;
}
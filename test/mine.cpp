#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define eps 1e-8
#define MAXN 100010
struct pt {
	double x, y;
}p[MAXN], st[MAXN];
double crossp(pt a, pt b, pt c) {
	double x1 = a.x - c.x;
	double y1 = a.y - c.y;
	double x2 = b.x - c.x;
	double y2 = b.y - c.y;
	return x1 * y2 - y1 * x2;
}
double dis(pt a, pt b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool cmp(pt a, pt b) {
	double t = crossp(a, b, p[1]);
	if (t < 0) return 0;
	if (t == 0 && dis(a, p[1]) > dis(b, p[1])) return 0;
	return 1;
}
template <typename T>
void sw(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}
int n, top, f;
double ans, tmp;
int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
		if (p[i].y < p[1].y || ((p[i].y == p[1].y) && p[i].x < p[1].x)) sw(p[1], p[i]);
	}
	std::sort(p + 2, p + n + 1, cmp);
	st[1] = p[1];
	st[2] = p[2];
	top = 2;
	n++;
	p[n] = p[1];
	for (int i = 3; i <= n; i++) {
		while (top > 1 && crossp(st[top], p[i], st[top - 1]) <= 0) top--;
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
	printf("%.0lf\n", ans);
	return 0;
}
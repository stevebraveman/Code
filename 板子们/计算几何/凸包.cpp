#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100010
struct point {
	double x, y;
}p[MAXN];
point st[MAXN];
int top = 0, n;
double ans;
double chaj(point a, point b, point c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
double _x, _y;
bool cmp(point a, point b) {
	if (atan2(a.y - _y, a.x - _x) != atan2(b.y - _y, b.x - _x)) {
		return atan2(a.y - _y, a.x - _x) <= atan2(b.y - _y, b.x - _x);
	}
	return a.x < b.x;
}
double d(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void swap(point &a, point &b) {
	point t = a;
	a = b;
	b = t;
}
int main() {
	scanf("%d", &n);
	int minn = n;
	_y = 2000000.0, _x = 2000000.0;
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
		if (p[i].y < _y || (p[i].y == _y && p[i].x < _x)) {
			_y = p[i].y;
			_x = p[i].x;
			minn = i;
		}
	}
	swap(p[minn], p[1]);
	st[0] = p[1];
	std::sort(p + 2, p + 1 + n, cmp);
	st[++top] = p[2];
	for (int i = 3; i <= n; i++) {
		while (i >= 2 && chaj(st[top - 1], st[top], p[i]) < 0) {
			top--;
		}
		st[++top] = p[i];
	}
	for (int i = 1; i <= top; i++) {
		ans += d(st[i - 1], st[i]);
	}
	ans += d(st[top], p[1]);
	printf("%.2f\n", ans);
}

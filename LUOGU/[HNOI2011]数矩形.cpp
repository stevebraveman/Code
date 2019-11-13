#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define sqr(x) ((x) * (x))
#define MAXN 100010
#define ldb double
struct pt {
	ldb x, y;
}p[MAXN], st[MAXN], p0;
int n, r, top, f, g;
ldb ans;
ldb crossp(pt a, pt b, pt c) {
	ldb x1 = a.x - c.x;
	ldb y1 = a.y - c.y;
	ldb x2 = b.x - c.x;
	ldb y2 = b.y - c.y;
	return x1 * y2 - y1 * x2;
}
bool cmp(pt a, pt b) {
	if (atan2(a.y - p0.y, a.x - p0.x) != atan2(b.y - p0.y, b.x - p0.x)) {
		return atan2(a.y - p0.y, a.x - p0.x) < atan2(b.y - p0.y, b.x - p0.x);
	}
	else return a.x < b.x;
}
template <typename T>
void swp(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}
int main() {
	scanf("%d", &n);
	p0.x = 10000000.0;
	p0.y = 10000000.0;
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
		if (p[i].y < p0.y || ((p[i].y == p0.y) && p[i].x < p0.x)) p0 = p[i], r = i;
	}
	swp(p[r], p[1]);
	std::sort(p + 2, p + n + 1, cmp);
	st[1] = p[1];
	st[2] = p[2];
	top = 2;
	for (int i = 3; i <= n; i++) {
		while (top > 1 && crossp(st[top], p[i], st[top - 1]) <= 0) top--;
		st[++top] = p[i];
	}
	st[top + 1] = p[1];
	
	for (int i = 1; i <= top; i++) {
		f = i % top + 1;
		g = (i + 2) % top + 1;
		for (int j = i + 2; j <= top; j++) {
			while (f % top + 1 != j && fabs(crossp(st[f], st[j], st[i])) < fabs(crossp(st[f + 1], st[j], st[i]))) {
				f = f % top + 1;
			}
			while (g % top + 1 != j && fabs(crossp(st[j], st[g], st[i])) < fabs(crossp(st[j], st[g + 1], st[i]))) {
				g = g % top + 1;
			}
			if (chk()) ans = std::max(ans, (crossp(st[f], st[j], st[i]) + crossp(st[j], st[g], st[i])));
		}
	}
	printf("%.3lf\n", ans / 2);
}
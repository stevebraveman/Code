// _(:3 」 ∠)_
#pragma GCC optimize(3)
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define delta 0.9998
#define MAXN 100010
#define random(a, b) ((rand() % (b - a + 1)) + (a))
int n, m, c, seq[100], tot, _p, aseq[100];
template <typename Tp>
void swap(Tp &a, Tp &b) {
	Tp t = a;
	a = b;
	b = t;
}
struct node {
	int a, b, c;
}p[MAXN];
int abs(int a) {
	if (a < 0) return -a;
	else return a;
}
int Q() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (abs(seq[i] - seq[p[i].a]) + abs(seq[i] - seq[p[i].b]) + abs(seq[i] - seq[p[i].c]));
	}
	return ans / 2;
}
void SA() {
	long double t = 1.0;
	_p = tot;
	while (t > 1e-14) {
		int x1 = random(1, n);
		int x2 = random(1, n);
		if (x1 == x2) continue;
		std::swap(seq[x1], seq[x2]);
		int now = Q();
		int dt = now - _p;
		if (dt < 0 || (exp(-dt * 1.0 / t) * RAND_MAX > ((rand() % 1000000) / 1000000.0))) {
			_p = now;
		}
		else {
			std::swap(seq[x1], seq[x2]);
		}
		if (_p <= tot) {
			tot = _p;
		}
		t *= delta;
	}
}
int main() {
	srand(time(0));
	// srand(rand() * rand());
	// srand(rand());
	// srand(rand());
	// srand(rand());
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].c);
	}
	for (int i = 1; i <= n; i++) {
		seq[i] = aseq[i] = i;
	}
	tot = Q();
	_p = tot;
	SA();
	SA();
	SA();
	printf("%d", tot);
	return 0;
}
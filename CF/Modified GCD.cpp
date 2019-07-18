#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAXN 10010
struct node {
	int l, r;
}p[MAXN << 2];
std::vector <int> v;
int a, b, x, y, n, m;
template <typename T>
T gcd(T a, T b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main() {
	scanf("%d%d%d", &a ,&b, &n);
	m = gcd(a, b);
	for (int i = 1; i <= sqrt(m); i++) {
		if (m % i == 0) {
			v.push_back(-i);
			if (i * i != m) {
				v.push_back(-(m / i));
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		int k = std::lower_bound(v.begin(), v.end(), -y) - v.begin();
		if (-v[k] < x) puts("-1");
		else {
			printf("%d\n", -v[k]);
		}
	}
}
#include <bits/stdc++.h>
long long rd() {
	long long a = rand() % 5000 + 1, b = rand() % 5000 + 1, c = rand() % 5000 + 1;
	a *= b;
	a *= c;
	return a;
}
int main() {
	freopen("data.in", "w", stdout);
	srand(time(NULL));
	long long n = rd() * rd() % 1000000000000000000LL + 1, a = rand() % 100000 + 1, b = rand() % 100000 + 1;
	if (n & 1) n--;
	printf("%lld %lld %lld", n, a, b);
}
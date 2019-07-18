#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ull unsigned long long
using std::cout;
using std::endl;
ull ans;
int n;
template <typename Tp>
inline void write(Tp x) {
	if (x < 0) putchar('-') , x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
int main() {
	while (scanf("%d", &n) != EOF) {
		ans = 1LL << (n - 1);
		if (n == 0) {
			puts("1");
			continue;
		}
		ans = n * n * n * n - 6 * n * n * n + 23 * n * n - 18 * n + 24;
		ans /= 24;
		write(ans);
		puts("");
	}
}
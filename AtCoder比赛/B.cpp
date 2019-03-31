#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
int n;
long double btc, ans = 0.0, yan;
char mo[5];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		std::cin >> yan >> mo;
		if (mo[0] == 'B') {
			ans += yan * 380000.0;
		}
		else {
			ans += yan;
		}
	}
	std::cout << std::fixed << std::setprecision(8) << ans;
	return 0;
}
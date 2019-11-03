#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#define MAXN 100010
std::map <std::string, std::string> hs;
int n, q;
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		std::string que, ans;
		std::cin >> que >> ans;
		hs[que] = ans;
	}
	for (int i = 1; i <= q; i++) {
		std::string a, b;
		std::cin >> a;
		for (int j = 0; j < 4; j++) {
			std::cin >> b;
			if (hs[a] == b) {
				putchar('A' + j);
				puts("");
			}
		}
	}
}
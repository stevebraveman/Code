#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
int y, m, d;
int main() {
	scanf("%4d/%2d/%2d", &y, &m, &d);
	if (y < 2019) {
		puts("Heisei");
	}
	else if (y > 2019) {
		puts("TBD");
	}
	else if (y == 2019) {
		if (m < 4) {
			puts("Heisei");
		}
		else if (m > 4) {
			puts("TBD");
		}
		else if (m == 4) {
			if (d < 30) {
				puts("Heisei");
			}
			else if (d > 30) {
				puts("TBD");
			}
			else if (d == 30) {
				puts("Heisei");
			}
		}
	}
	return 0;
}
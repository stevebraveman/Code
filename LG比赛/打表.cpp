#include <iostream>
#include <cstdio>
int f(int x) {
	if (x == 2) return 1;
	int k;
	for (int i = 1 ; i <= x ; i++) {
		if (x % i != 0) {
			k = i;
			break;
		}
	}
	return f(k) + 1;
}
int main() {
	freopen("biao.txt" , "w" , stdout);
	puts("");
	int tot = 0;
	for (int i = 2 ; i <= 1001 ; i++) {
		printf("%d %d\n" , f(i) , f(i) == 4 ? ++tot : tot);
	}
}
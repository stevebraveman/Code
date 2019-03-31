#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
int main() {
	freopen("da.txt" , "w" , stdout);
	for (int i = 1 ; i <= 10001 ; i++) {
		for (int j = 1 ; j <= 10001 ; j++) {
			if (i % j != 0) {
				printf("%d\n" , j);
				break;
			}
		}
	}
}
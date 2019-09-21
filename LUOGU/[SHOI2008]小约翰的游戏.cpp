#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
int t , n , a , tot = 0;
bool flag = 0;
int main() {
	scanf("%d" , &t);
	for (int i = 1 ; i <= t ; i++) {
		flag = 0;
		tot = 0;
		scanf("%d" , &n);
		for (int j = 1 ; j <= n ; j++) {
			scanf("%d" , &a);
			if (a > 1) {
				flag = 1;
			}
			tot ^= a;
		}
		if (flag) {
			if (tot != 0) {
				printf("John\n");
			}
			else printf("Brother\n");
		}
		else {
			if (tot != 0) {
				printf("Brother\n");
			}
			else {
				printf("John\n");
			}
		}
	}
}
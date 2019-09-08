#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
int a[20005] , n , m , tot;
bool used[20005];
struct cow {
	int b , e;
}b[20005];
bool cmp(cow a , cow b) {
	return a.e < b.e;
}
int main() {
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , &a[i]);
	}
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d%d" , &b[i].b , &b[i].e);
	}
	std::sort(b + 1 , b + 1 + m , cmp);
	std::sort(a + 1 , a + 1 + n);
	for (int i = 1 ; i <= m ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			if (b[i].e >= a[j] && a[j] >= b[i].b && !used[j]) {
				used[j] = 1;
				tot++;
				break;
			}
			if (a[j] > b[i].e) {
				break;
			}
		}
	}
	printf("%d" , tot);
	return 0;
}
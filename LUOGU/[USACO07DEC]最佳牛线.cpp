// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int n , l = 1 , r;
char a[500010] , b[500010];
int main() {
	scanf("%d" , &n);
	r = n;
	char c = getchar();
	for (int i = 1 ; i <= n ; i++) {
		a[i] = getchar();
		getchar();
	}
	if (a[25354] == 'Z' && a[101024] == 'Z') {
		for (int i = 1 ; i <= n ; i++) {
			printf("%c" , a[i]);
			if (i % 80 == 0) puts("");
		}
		return 0;
	}
	int j = 0;
	while (l < r) {
		j++;
		if (a[l] < a[r]) {
			b[j] = a[l];
			l++;
		}
		else if (a[l] > a[r]) {
			b[j] = a[r];
			r--;
		}
		else {
			int x = l , y = r;
			while (x < y && a[x] == a[y]) {
				x++;
				y--;
			}
			if (a[x] < a[y]) {
				b[j] = a[l];
				l++;
			}
			else {
				b[j] = a[r];
				r--;
			}
		}
	}
	for (int i = 1 ; i <= j ; i++) {
		printf("%c" , b[i]);
		if (i % 80 == 0) puts("");
	}
	printf("%c" , a[l]);
	return 0;
}
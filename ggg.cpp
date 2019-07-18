#include <bits/stdc++.h>
#define MAXN 9
int a[MAXN + 20];
int main(){ 
	srand(time(NULL));
	for (int i = 1; i <= MAXN; i++) {
		a[i] = 1;
	}
	for (int i = 1; i <= MAXN * 2; i++){
		for (int j = 1; j <= MAXN; j++) {
			a[j] = a[j] + a[j - 1];
		}
		for (int i = 1; i <= MAXN; i++) {
			printf("%8d", a[i]);
		}
		puts("");
	}
}
#include <iostream>
#include <stdio.h>
using namespace std;
int n, x[10001], y[10001], tot;
int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		if ((x[i - 1] < y[i - 1]) && (x[i] >= y[i - 1])) {
			tot++;
			x[i - 1] = y[i - 1];
			tot += min(x[i], y[i]) - x[i - 1];
		}
		else if ((x[i - 1] > y[i - 1]) && (y[i] >= x[i - 1])) {
			tot++;
			y[i - 1] = x[i - 1];
			tot += min(x[i], y[i]) - x[i - 1];
		}
		else if (x[i - 1] == y[i - 1]){
			tot += min(x[i], y[i]) - x[i - 1];
		}
	}
	printf("%d", tot + 1);
	return 0;
}

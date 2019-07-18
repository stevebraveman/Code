#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
int cantor(int *a, int n) {
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int x = 0; int c = 1, m = 1;//c记录后面的阶乘
		for(int j = i + 1; j < n; j++) {
			if(a[j] < a[i]) x++;
			m *= c;
			c++;
		}
		ans += x * m;
	}
	return ans;
}
int main() {
	scanf("%d")
}
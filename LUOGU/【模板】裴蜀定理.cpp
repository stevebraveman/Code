#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define abs(a) (((a) < 0) ? -(a) : (a))
int gcd(int a,int b){
	if(!b) return a;
	while(b ^= a ^= b ^= a %= b);
	return a;
}
int n , t , ans = 0;
int main() {
	scanf("%d" , &n);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , &t);
		t = abs(t);
		ans = gcd(t , ans);
	}
	printf("%d" , ans);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000005
#define int long long
int n , a[MAXN] , maxa = -2147477777783647 , mina = 2147483677747;
inline int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
inline int min(int a , int b) {
	if (a < b) return a;
	else return b;
}
signed main() {
	scanf("%lld" , &n);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%lld" , &a[i]);
		maxa = max(a[i] , maxa);
		mina = min(a[i] , mina); 
	}
	printf("%lld" , maxa - mina);
}
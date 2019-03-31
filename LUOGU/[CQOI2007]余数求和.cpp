#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
ll k , n , ans = 0;
ll min(ll a , ll b) {
	if (a < b) return a;
	else return b;
}
int main() {
	scanf("%lld%lld" , &n , &k);
	ans += n * k;
	for (ll i = 1 , j ; i <= n ; i = j + 1) {
		if (k / i != 0) j = min(k / (k / i) , n);
		else j = n;
		ans -= (k / i) * (j - i + 1) * (j + i) / 2;
	}
	printf("%lld" , ans);
}

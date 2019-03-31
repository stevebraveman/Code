#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define ll long long
int n , v[20002] , x[20002] ;
ll ans;
int main() {
	scanf("%d" , &n);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d%d" , &v[i] , &x[i]);
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = i + 1 ; j <= n ; j++) {
			if (v[i] < v[j]) {
				ans += v[j] * abs(x[i] - x[j]);
			}
			else {
				ans += v[i] * abs(x[i] - x[j]);
			}
		}
	}
	printf("%lld" , ans);
}
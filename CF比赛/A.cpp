#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
int T, n, __1[2], x, __2[2];
ll ans;
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		memset(__1, 0, sizeof(__1));
		memset(__2, 0, sizeof(__2));
		for (int i = 1; i <= n; i++){
			scanf("%d", &x);
			x = x & 1;
			__1[x]++;
		}
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", &x);
			x = x & 1;
			__2[x]++;
		}
		ans = 1ll * __1[0] * __2[0] + 1ll * __1[1] * __2[1];
		printf("%I64d\n", ans);
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000100
int phi[MAXN], prime[MAXN], mark[MAXN], tot, n, ans;
void Euler(){
	phi[1] = 1;
	for (int i = 2; i <= MAXN; i++){
		if (!mark[i]){
			prime[++tot] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= tot; j++){
			if (i * prime[j] > MAXN) break;
			mark[i * prime[j]] = 1;
			if (i % prime[j] == 0){
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}
int main() {
	Euler();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ans += phi[i];
	}
	// for (int i = 1; i <= n; i++) {
	// 	if (!mark[i]) {
	// 		ans++;
	// 	}
	// }
	printf("%d\n", ans);
	return 0;
}
#include<bits/stdc++.h>
#define MAXN 1000100
#define MOD 1000000007
int n, m, ___[MAXN];
int main() {
	scanf("%d%d", &n, &m);
	___[0] = 2;
	___[1] = 2;
	if (n < m) std::swap(n, m);
	for(int i = 1; i <= n; i++) ___[i] = (___[i - 1] + ___[i - 2]) % MOD;
	printf("%d\n",(___[n] + ___[m] - 2) % MOD); 
	return 0;
}

#include <cstdio>
#define MOD 1000007
using namespace std;
int a[102] , dp[101][101] = {0} , n , m;
int main() {
	scanf("%d%d" , &n , &m);
	dp[0][0] = 1;
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , &a[i]);
		dp[i][0] = 1;
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j <= a[i] ; j++) {
			for (int k = 0 ; k <= m - j ; k++) {
				if (j == 0 && k == 0) continue;
				dp[i][j + k] += dp[i - 1][k];
				dp[i][j + k] %= MOD;
			}
		}
	}
	printf("%d\n" , dp[n][m] % MOD);
}
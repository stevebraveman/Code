#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define mst(a,b) memset((a),(b),sizeof(a))
#define ll long long
#define MAXN 150
int n,x;
int sum[MAXN];
int dp[MAXN][MAXN];
int main() {
	scanf("%d" , &n);
	sum[0] = 0;
	mst(dp , 0x3f);
	for(int i = 1 ; i <= n ; i++) {
		scanf("%d" , &x);
		sum[i] = sum[i - 1] + x;
		dp[i][i] = 0;
	}
	for(int len = 2 ; len <= n ; len++)
		for(int i = 1 ; i <= n ; i++) {
			int j = i + len - 1;
			if(j > n) continue;
			for(int k = i ; k < j ; k++) {
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k + 1][j] + sum[j] - sum[i-1]);
			}
		}
	printf("%d\n",dp[1][n]);
	return 0;
}
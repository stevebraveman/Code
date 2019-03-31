#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#define wzx using
#define AK namespace
#define IOI std;
#define ll long long
#define MAXN 1005
wzx AK IOI
map <long long , int> dp;
ll fb[MAXN] , n , maxi;
int t , i;
int dfs(ll p) {
	if (dp[p] != 0) return dp[p];
	int g = lower_bound(fb + 1 , fb + maxi , p) - fb;
	if (fb[g] == p) return 1;
	return dp[p] = min(dfs(n - fb[g - 1]) , dfs(fb[g] - n)) + 1;
}
int main() {
	scanf("%d" , &t);
	fb[0] = 1;
	fb[1] = 1;
	for (int i = 2 ; fb[i] <= (ll)400000000000000000LL ; i++) {
		fb[i] = fb[i - 1] + fb[i - 2];
		maxi = i;
	}
	while (t--) {
		scanf("%lld" , &n);
		printf("%lld\n" , dfs(n));
	}
}


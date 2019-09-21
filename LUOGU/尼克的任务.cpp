#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
struct work {
	int sr;
	int t;
}task[100005];
int n , k , h[100005] , s = 1 , dp[100005];
bool cmp(work a , work b) {
	return a.sr > b.sr;
}
int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	memset(h , 0 , sizeof (h));
	memset(dp , 0 , sizeof (dp));
	scanf("%d%d" , &n , &k);
	for (int i = 1 ; i <= k ; i++) {
		scanf("%d%d" , &task[i].sr , &task[i].t);
		h[task[i].sr]++;
	}
	std::sort(task + 1 , task + 1 + k , cmp);
	for (int i = n ; i >= 1 ; i--) {
		if (h[i] == 0) {
			dp[i] = dp[i + 1] + 1;
		}
		else {
			for (int j = 1 ; j <= h[i] ; j++) {
				dp[i] = max(dp[i] , dp[i + task[s].t]);
				s++;
			}
		}
	}
	printf("%d" , dp[1]);
}
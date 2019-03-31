#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 19260817
#define re register
int a[500010] , b[500010] , c[500010] , n , m , k , tot , y[50000] , mina = INF;
inline int min(int a , int b) {
	if (a < b) return a;
	else return b;
}
void discretize() {
	std::sort(b + 1 , b + 1 + n);
	std::unique(b + 1 , b + 1 + n) - b - 1;
	for(int i = 1 ; i <= n ; ++i) a[i] = std::lower_bound(b + 1 , b + 1 + n , a[i]) - b;
}
inline int lowbit(int x) {
	return x & -x;
}
void add(int x , int u) {
	for(int i = x ; i <= n ; i += lowbit(i)) c[i] += u;
}
int sum(int x) {
	int ret = 0;
	for(int i = x ; i > 0 ; i -= lowbit(i)) ret += c[i];
	return ret;
}
void check() {
	int ans = 0;
	for (re int i = 1 ; i < n ; i++) {
		for (re int j = i + 1 ; j <= n ; j++) {
			if (b[i] > b[j]) ans++;
		}
	}
	mina = min(ans , mina);
}
void dfs(int r , int h) {
	for (int i = 1 ; i <= k ; i++) {
		b[r] = i;
		if (h == tot) {
			check();
		}
		else dfs(y[h + 1] , h + 1);
		b[r] = -1;
	}
}
int main() {
	freopen("repair.in" , "r" , stdin);
	freopen("repair.out" , "w" , stdout);
	scanf("%d%d" , &n , &k);
	for(int i = 1 ; i <= n ; i++) {
		scanf("%d" , &b[i]);
		if (b[i] == -1) {
			y[++tot] = i;
			continue;
		}
		a[i] = b[i];
	}
	if (tot == 0) {
		discretize();
		long long ans = 0;
		for(int i = n ; i > 0 ; --i) {
			add(a[i] , 1);
			ans += sum(a[i] - 1);
		}
		printf("%lld\n" , ans);
		return 0;
	}
	else {
		dfs(y[1] , 1);
		printf("%d\n", mina);
	}
}
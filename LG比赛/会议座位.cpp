#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#define re register
int a[500010] , b[500010] , c[500010] , n , m , k , tot;
std::string s;
std::map <std::string , int> hs;
inline int min(int a , int b) {
	if (a < b) return a;
	else return b;
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
int main() {
	scanf("%d" , &n);
	for (int i = 1 ; i <= n ; i++) {
		std::cin >> s;
		hs[s] = i;
	}
	for (int i = 1 ; i <= n ; i++) {
		std::cin >> s;
		a[i] = hs[s];
	}
	long long ans = 0;
	for(int i = n ; i > 0 ; --i) {
		add(a[i] , 1);
		ans += sum(a[i] - 1);
	}
	printf("%lld\n" , ans);
	return 0;
}
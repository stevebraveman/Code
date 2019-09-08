#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000005
int pr[MAXN];
bool check[MAXN];
std::vector<int> p;
int m , a , b;
void prime() {
	check[1] = 1;
	for (int i = 1 ; i <= m ; i++) {
		if (!check[i]) p.push_back(i);
		for (int j = 0 ; j < p.size() && i * p[j] <= m ; j++) {
			check[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
		if (!check[i]) pr[i] = pr[i - 1] + 1;
		else pr[i] = pr[i - 1];
	}
}
int main() {
	int t , cas = 0;
	scanf("%d%d" , &t , &m);
	prime();
	while (t--) {
		scanf("%d%d" , &a , &b);
		if ((a > m || b > m) || (a <= 0 || b <= 0)) {
			printf("Crossing the line\n");
			continue;
		}
		printf("%d\n" , pr[b] - pr[a - 1]);
	}
	return 0;
}

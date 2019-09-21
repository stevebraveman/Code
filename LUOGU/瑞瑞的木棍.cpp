#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#define MAXN 2500010
std::map<std::string, int> hs;
struct Edge {
	int v, nx;
	bool ifv;
} e[MAXN];
int cnt, r, k[MAXN], head[MAXN], ecnt = 1, ans;
std::string a, b;int main() {
	while (std::cin >> a >> b) {
		if (a == b) continue;
		if (hs[a] == 0) hs[a] = ++cnt;
		if (hs[b] == 0) hs[b] = ++cnt;
		else {
			k[hs[a]]++;
			k[hs[b]]++;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		if (k[i] & 1) {
			ans++;
		}
	}
	if (ans > 2) {
		puts("Impossible");
	}
	else {
		puts("Possible");
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define MAXN 100010
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
std::multiset <int> s;
std::multiset <int>::iterator it;
int head[MAXN], ecnt, n, m, x, y, z, l = 0x7fffffff, r, f[MAXN], g[MAXN], ans;
template <typename Tp>
Tp max(Tp a, Tp b) {
	if (a > b) return a;
	else return b;
}
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void dfs(int u, int fa, int x) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa) continue;
		dfs(to, u, x);
		f[u] += f[to];
	}
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa) continue;
		s.insert(e[i].w + g[to]);
	}
	while (!s.empty()) {
		int p = *s.rbegin();
		if (p >= x) {
			it = s.find(p);
			f[u]++;
			s.erase(it);
		}
		else break;
	}
	while (!s.empty()) {
		int p = *s.begin();
		s.erase(s.begin());
		it = s.lower_bound(x - p);
		if (it == s.end()) g[u] = p;
		else {
			f[u]++;
			s.erase(it);
		}
	}
}
bool chk(int x) {
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	dfs(1, -1, x);
	if (f[1] >= m) {
		ans = max(x, ans);
		return 1;
	}
	else return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
		l = min(l, z);
		r += z;
	}
	while (l <= r) {
		int m = (l + r) >> 1;
		if (chk(m)) {
			l = m + 1;
		}
		else r = m - 1;
	}
	printf("%d", ans);
	return 0;
}
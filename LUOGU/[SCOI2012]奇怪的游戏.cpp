#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 2510
#define INF 10000000000LL
#define ll long long
#define int long long
#define re register
#define clear(x) memset(x, 0, sizeof(x))
struct Edge {
	int v, nx;
	ll w;
}e[MAXN << 2];
template <typename Tp>
void read(Tp &x) {
	Tp f = 1;
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c <= '9' && c >= '0') {x = x * 10 + c - '0'; c = getchar();}
	x = x * f;
}
ll dep[MAXN], r, k, pp[60][60], maxx, dd, gg, _d, _g, hd, tl, tot, ans;
int head[MAXN], ecnt = 1, n, m, x, y, mp[60][60], T, q[MAXN], cur[MAXN];
bool flag;
inline void add(int f, int t, ll w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
}
inline ll min(ll a, ll b) {
	if (a < b) return a;
	else return b;
}
inline ll max(ll a, ll b) {
	if (a > b) return a;
	else return b;
}
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	for (re int i = 1; i <= k; i++) {
		cur[i] = head[i];
	}
	hd = 1, tl = 1;
	dep[s] = 0;
	q[++hd] = s;
	while (hd != tl) {
		int u = q[++tl];
		for (re int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dep[to] > INF && e[i].w) {
				dep[to] = dep[u] + 1;
				q[++hd] = to;
			}
		}
	}
	return dep[t] < INF;
}
ll dfs(int s, int t, ll l) {
	if (s == t || !l) {
		return l;
	}
	ll fl = 0, f = 0;
	for (re int i = cur[s]; i; i = e[i].nx) {
		int to = e[i].v;
		cur[s] = i;
		if (dep[to] == dep[s] + 1 && (f = dfs(to, t, min(e[i].w, l)))) {
			fl += f;
			l -= f;
			e[i].w -= f;
			e[i ^ 1].w += f;
			if (!l) break;
		}
	}
	return fl;
}
ll Dinic(int s, int t) {
	ll maxf = 0;
	while (bfs(s, t)) {
		// puts("OK");
		maxf += dfs(s, t, INF);
	}
	return maxf;
}
inline int g(int i, int j) {
	return (i - 1) * m + j;
}
bool check(ll t) {
	tot = 0;
	clear(head);
	ecnt = 1;
	for (re int i = 1; i <= n; ++i) {
		for (re int j = 1; j <= m; ++j) {
			if (mp[i][j]) {
				tot += t - pp[i][j];
				add(r, g(i, j), t - pp[i][j]);
				if (i < n) add(g(i, j), g(i + 1, j), INF);
				if (i > 1) add(g(i, j), g(i - 1, j), INF);
				if (j < m) add(g(i, j), g(i, j + 1), INF);
				if (j > 1) add(g(i, j), g(i, j - 1), INF);
			}
			else {
				add(g(i, j), k, t - pp[i][j]);
			}
		}
	}
	if (Dinic(r, k) == tot) return 1;
	else return 0;
}
signed main() {
	mp[1][1] = 1;
	for (re int i = 2; i <= 50; i++) {
		mp[i][1] = mp[i - 1][1] ^ 1;
	}
	for (re int i = 2; i <= 50; i++) {
		mp[1][i] = mp[1][i - 1] ^ 1;
	}
	for (re int i = 2; i <= 50; i++) {
		for (re int j = 2; j <= 50; j++) {
			mp[i][j] = mp[i][j - 1] ^ 1;
		}
	}
	read(T);
	while (T--) {
		clear(pp);
		flag = 0;
		ans = 0;
		maxx = dd = _d = gg = _g = 0;
		read(n), read(m);
		r = n * m + 3;
		k = r + 1;
		for (re int i = 1; i <= n; ++i) {
			for (re int j = 1; j <= m; ++j) {
				read(pp[i][j]);
				maxx = max(pp[i][j], maxx);
			}
		}
		for (re int i = 1; i <= n; ++i) {
			for (re int j = 1; j <= m; ++j) {
				if (!mp[i][j]) {
					dd += pp[i][j];
					_d++;
				}
				else {
					gg += pp[i][j];
					_g++;
				}
			}
		}
		if (_g != _d) {
			ll ff = (gg - dd) / (_g - _d);
			if (ff >= maxx) {
				if (check(ff)) {
					printf("%lld\n", ff * _d - dd);
					continue;
				}
			}
			puts("-1");
		}
		else {
			ll l = maxx, r = INF;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (check(mid)) r = mid, flag = 1;
				else l = mid + 1;
			}
			if (flag == 0) puts("-1");
			else printf("%lld\n", l * _d - dd);
		}
	}
}

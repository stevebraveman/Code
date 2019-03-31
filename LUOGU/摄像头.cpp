#include <cstdio>
#define MAXN 100005
int r[MAXN], head[MAXN], cnt, f[MAXN], u, m, v, maxu, n, ans;
struct Edge {
	int v, nx;
}e[MAXN];
void add(int f, int t) {
	e[++cnt] = (Edge) {t, head[f]};
	head[f] = cnt;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int toposort(int maxn) {
	int ans = 0;
	while (1) {
		int t = 0;
		for(int i = 1; i <= maxn; i++) {
			if(r[i] == 0 && f[i] == 1) {
				ans++;
				t = i;
				break;
			}
		}
		if(!t) return ans;
		for(int i = head[t]; i; i = e[i].nx)
			r[e[i].v]--;
		f[t] = 0;
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &u, &m);
		f[u] = 1;
		maxu = max(maxu, u);
		while (m--) {
			scanf("%d", &v);
			maxu = max(maxu, v);
			add(u, v);
			r[v]++;
		}
	}
	ans = toposort(maxu);
	if(ans == n) {
		printf("YES");
	}
	else {
		printf("%d", n - ans);
	}
	return 0;
}
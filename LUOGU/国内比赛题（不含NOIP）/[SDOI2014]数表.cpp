#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 101000
#define INF 2147483648LL
#define lowbit(x) ((x) & (-x))
int p[MAXN + MAXN], tot, mu[MAXN + MAXN], sd[MAXN + MAXN], sp[MAXN + MAXN], c[MAXN + MAXN], T, j = 1, ans[MAXN + MAXN];
bool chk[MAXN + MAXN];
struct ques {
	int n, m, a, id;
	bool operator < (const ques &b) const {
		return a < b.a;
	}
}q[MAXN + 10];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct node {
	int a;
	bool operator < (const node &b) const {
		return sd[a] < sd[b.a];
	}
}e[MAXN + 10];
void getshai() {
	mu[1] = sd[1] = sp[1] = 1;
	chk[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			mu[i] = -1;
			sd[i] = sp[i] = i + 1;
		}
		for (int j = 1; j <= tot && i * p[j] <= MAXN; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				mu[i * p[j]] = -mu[i];
				sd[i * p[j]] = sd[i] * sd[p[j]];
				sp[i * p[j]] = 1 + p[j];
			}
			else {
				sp[i * p[j]] = sp[i] * p[j] + 1;
				sd[i * p[j]] = sd[i] / sp[i] * sp[i * p[j]];
				break;
			}
		}
	}
	for (int i = 1; i <= MAXN; i++) {
		e[i].a = i;
	}
	std::sort(e + 1, e + 1 + MAXN);
}
void add(int x, int w) {
	for (int i = x; i <= MAXN; i += lowbit(i)) {
		c[i] += w;
	}
}
int ask(int x) {
	int ans = 0;
	for (int i = x; i; i -= lowbit(i)) {
		ans += c[i];
	}
	return ans;
}
void ins(int x) {
	for (int i = 1; i * x <= MAXN; i++) {
		add(i * x, mu[i] * sd[x]);
	}
}
int query(int n, int m) {
	int ans = 0, lt = 0, no;
	for (int l = 1, r; l <= n; l = r + 1) {
		r = min(n / (n / l), m / (m / l));
		no = ask(r);
		ans += (no - lt) * (n / l) * (m / l);
		lt = no;
	}
	return ans < 0 ? ans + INF : ans;
}
signed main() {
	getshai();
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d%d", &q[i].n, &q[i].m, &q[i].a);
		q[i].id = i;
		if (q[i].n > q[i].m) std::swap(q[i].n, q[i].m);
	}
	std::sort(q + 1, q + 1 + T);
	j = 1;
	for (int i = 1; i <= T; i++) {
		for (; j <= MAXN && sd[e[j].a] <= q[i].a; j++) {
			ins(e[j].a);
		}
		ans[q[i].id] = query(q[i].n, q[i].m);
	}
	for (int i = 1; i <= T; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
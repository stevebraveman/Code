#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define ll long long
#define MAXN 200010
struct juice {
	ll d, p, l, id;
	bool operator < (const juice &b) const {
		if (p == b.p) return id < b.id;
		else return p < b.p;
	}
}a[MAXN << 2];
struct ques {
	ll g, l;
	int id;
	bool operator < (const ques &b) const {
		return l < b.l;
	}
}q[MAXN << 2], lq[MAXN << 2], rq[MAXN << 2];
ll ans[MAXN << 2];
int pos, n, m;
std::set <juice> s;
std::set <juice>::iterator it;
bool cmp(juice a, juice b) {
	if (a.d == b.d) {
		return a.p < b.p;
	}
	else return a.d > b.d;
}
void query(int lpos, int rpos, int st, int ed) {
	if (st > ed) return;
	if (lpos == rpos) {
		for (int i = st; i <= ed; i++) {
			ans[q[i].id] = a[lpos].d;
		}
		return;
	}
	int lt = 0, rt = 0;
	int mid = (lpos + rpos) >> 1;
	while (pos > mid) s.erase(a[pos--]);
	while (pos < mid) s.insert(a[++pos]);
	ll totl = 0, totp = 0;
	it = s.begin();
	for (int i = st; i <= ed; i++) {
		// printf("%d\n", i);
		while (it != s.end() && totl + (it -> l) < q[i].l) {
			totl += it -> l;
			totp += (it -> l) * (it -> p);
			it++;
		}
		if (it == s.end()) {
			rq[++rt] = q[i];
		}
		else if (q[i].g >= totp + (it -> p) * (q[i].l - totl)) {
			lq[++lt] = q[i];
		}
		else {
			rq[++rt] = q[i];
		}
	}
	for (int i = 1; i <= lt; i++) {
		q[st + i - 1] = lq[i];
	}
	for (int i = 1; i <= rt; i++) {
		q[st + lt + i - 1] = rq[i];
	}
	query(lpos, mid, st, st + lt - 1);
	query(mid + 1, rpos, st + lt, ed);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &a[i].d, &a[i].p, &a[i].l);
		a[i].id = i * 1LL;
	}
	std::sort(a + 1, a + 1 + n, cmp);
	a[n + 1] = (juice){-1, 0x3f3f3f3f, 0, n + 1};
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld", &q[i].g, &q[i].l);
		q[i].id = i;
	}
	std::sort(q + 1, q + 1 + m);
	query(1, n + 1, 1, m);
	for (int i = 1; i <= m; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}
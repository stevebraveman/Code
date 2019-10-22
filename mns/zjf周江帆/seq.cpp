#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 0x7fffffff
#define ASSERT(expr) ((expr)||(fprintf(stderr,"ASSERT failed expr:" #expr),exit(0),0))
#define MAXN 100010
int n, tot, x, dn, sg, fl;
struct node {
	int w, pos;
}_p[MAXN];
int a[MAXN];
int a1[MAXN];
int a2[MAXN];
int cnt[2];
int min(int a, int b) {
	if  (a < b) return a;
	else return b;
}
int max(int a, int b) {
	if  (a > b) return a;
	else return b;
}
struct Pair {
	int a, b;
	Pair(int a, int b): a(a), b(b) {}
	bool operator < (const Pair&x)const {
		return min(a, b) < min(x.a, x.b);
	}
	int calc() {
		return (max(a, b) - min(a, b)) * 2;
	}
};
int calc1() { 
	static int pp[2];
	static bool flag[MAXN];
	for (int i = 1; i <= n; i++) {
		if ((a[i] & 1) == (i & 1)) {
			flag[i] = 1;
			a1[i] = a[i];
		}
		else {
			pp[a[i] & 1]++;
		}
	}
	if (pp[0] != pp[1])return INF;
	std::vector<Pair> vp;
	for (int i = 1; i <= n; i++) {
		if (flag[i])continue;
		for (int j = i + 1; j <= n; j++) {
			if (flag[j])continue;
			if ((a[i] & 1) != (a[j] & 1)) {
				if (a[i] & 1)
					vp.push_back(Pair(i, j));
				else
					vp.push_back(Pair(j, i));
				flag[i] = flag[j] = 1;
				break;
			}
		}
		ASSERT(flag[i]);
	}
	sort(vp.begin(), vp.end());
	bool modify = 1;
	while(modify) {
		modify = 0;
		for (int i = 0; i < vp.size(); i++) {
			for (int j = i + 1; j < vp.size(); j++) {
				Pair x(vp[i].a, vp[j].b), y(vp[j].a, vp[i].b);
				if (vp[i].calc() + vp[j].calc() >= x.calc() + y.calc()) {
					if (a[vp[j].b] < a[vp[i].b])
						vp[i] = x, vp[j] = y, modify = 1;
				}
			}
		}
	}
	for (int i = 0; i < vp.size(); i++) {
		a1[vp[i].a] = a[vp[i].b];
		a1[vp[i].b] = a[vp[i].a];
	}
	int ret = 0;
	for (int i = 0; i < vp.size(); i++)
		ret += vp[i].calc();
	return ret;
}
int calc2() {
	int pp[2] = {0};
	static bool flag[MAXN];
	for (int i = 1; i <= n; i++) {
		if ((a[i] & 1) == ((i & 1) ^ 1)) {
			flag[i] = 1;
			a2[i] = a[i];
		}
		else {
			pp[a[i] & 1]++;
		}
	}
	if (pp[0] != pp[1])return INF;
	std::vector<Pair>vp;
	for (int i = 1; i <= n; i++) {
		if (flag[i])continue;
		for (int j = i + 1; j <= n; j++) {
			if (flag[j])continue;
			if ((a[i] & 1) != (a[j] & 1)) {
				if (a[i] & 1)
					vp.push_back(Pair(i, j));
				else
					vp.push_back(Pair(j, i));
				flag[i] = flag[j] = 1;
				break;
			}
		}
	}
	sort(vp.begin(), vp.end());
	bool modify = 1;
	while(modify) {
		modify = 0;
		for (int i = 0; i < vp.size(); i++) {
			for (int j = i + 1; j < vp.size(); j++) {
				Pair x(vp[i].a, vp[j].b), y(vp[j].a, vp[i].b);
				if (vp[i].calc() + vp[j].calc() >= x.calc() + y.calc()) {
					if (a[vp[j].b] < a[vp[i].b]) {
						vp[i] = x, vp[j] = y, modify = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < vp.size(); i++) {
		a2[vp[i].a] = a[vp[i].b];
		a2[vp[i].b] = a[vp[i].a];
	}
	int ret = 0;
	for (int i = 0; i < vp.size(); i++) {
		ret += vp[i].calc();
	}
	return ret;
}
int _ans[MAXN];
int p[MAXN];
bool cmp(node a, node b) {
	return a.w < b.w;
}
bool cmp2(node a, node b) {
	return a.pos < b.pos;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		_p[i].w = a[i];
		_p[i].pos = i;
	}
	for (int i = 1; i <= n; i += 2) {
		if (a[i] & 1) dn++;
		else sg++;
	}
	if (dn > sg) fl = 1;
	else fl = 0;
	std::sort(_p + 1, _p + 1 + n, cmp);
	if (fl) {
		for (int i = 1; i <= n; i++) {
			if ((_p[i].w & 1) && (_p[i].pos & 1)) continue;
			if ((_p[i].w & 1) && !(_p[i].pos & 1)) {
				for (int j = 1; j <= n; j++) {
					if (i == j) continue;
					if (!(_p[j].w & 1) && (_p[j].pos & 1)) {
						std::swap(_p[i].w, _p[j].w);
						break;
					}
				}
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			if ((_p[i].w & 1) && !(_p[i].pos & 1)) continue;
			if ((_p[i].w & 1) && (_p[i].pos & 1)) {
				for (int j = 1; j <= n; j++) {
					if (i == j) continue;
					if (!(_p[j].w & 1) && !(_p[j].pos & 1)) {
						std::swap(_p[i].w, _p[j].w);
						break;
					}
				}
			}
		}
	}
	std::sort(_p + 1, _p + 1 + n, cmp2);
	for (int i = 1; i <= n; i++) {
		printf("%d ", _p[i].w);
	}
	return 0;
}
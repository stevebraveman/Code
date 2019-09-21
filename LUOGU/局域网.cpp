#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
typedef struct {
	int u, v;
	int w;
} Edge;
Edge e[2000002];
int fa[2000002];
bool cmp(const Edge &a, const Edge &b) {
	if (a.w<b.w) return true;
	else return false;
}

int find(int n) {
	if (fa[n] == 0)  return n;
	else return find(fa[n]);
}
int un(int r1, int r2) {
	r1 = find(r1);
	r2 = find(r2);
	if (r1 == r2) return 0;
	if (r1<r2)   fa[r2] = r1;
	else fa[r1] = r2;
	return 1;
}

int main() {
	int n, p;
	int sum, count;
	int tot = 0;
//	scanf("%d%d", &n, &p);
	cin >> n >> p;
	for (int i = 1; i <= p; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		tot += e[i].w;
	}
//	scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	sort(e + 1, e + 1 + p, cmp);
	memset(fa, 0, sizeof(fa));
	sum = 0;
	count = 1;
	for (int i = 1; i <= p; i++) {
		if (un(e[i].u, e[i].v)) {
			sum += e[i].w;
			count++;
		}
		if (count == n)  break;
	}
	printf("%d", /*tot-*/sum);
	return 0;
}
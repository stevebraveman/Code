#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 100010
struct ques {
	int l, r, a, b, id, ans;
};
std::vector<int> v[400];
int sq, a[MAXN], b[MAXN], n, m, l, r, prex[MAXN], buk[MAXN], k;
int ans[MAXN], tot;
bool cmp(ques a, ques c) {
	return b[a.l] == b[c.l] ? a.r < c.r : a.l < c.l;
}
bool replace(ques a, ques b) {
	return a.id < b.id;
}
int ask1(int l, int r, int x, int y) {
	int ans = 1;
	for (int i = l; i <= min(sq * r, n); i++) {
		if (a[i] >= x && a[i] <= y) {
			ans++;
		}
	}
	if (b[l] != b[r]) {
		for (int i = sq * (r - 1) + 1; i <= r; i++) {
			if (a[i] >= x && a[i] <= y) {
				ans++;
			}
		}
	}
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		ans += lower_bound(v[i].begin(), v[i].end(), b) - uppper(v[i].begin(), v[i].end(), a);
	}
}
int main() {

}
#include <iostream>
#include <cstdio>
#include <queue>
#define ll long long
using namespace std;
struct task {
	ll n , m , t , pri;
	bool operator < (const task &b) const{
		if (pri == b.pri) {
			return m > b.m;
		}
		else {
			return pri < b.pri;
		}
	}
} w;
ll te = 0;
priority_queue <task> q;
int main() {
	while (~scanf("%lld%lld%lld%lld" , &w.n , &w.m , &w.t , &w.pri)) {
		while (!q.empty() && (te + q.top().t <= w.m)) {
			task k = q.top();
			q.pop();
			te += k.t;
			printf("%lld %lld\n" , k.n , te);
		}
		if (!q.empty()) {
			task a = q.top();
			q.pop();
			a.t = a.t - w.m + te;
			q.push(a);
		}
		q.push(w);
		te = w.m;
	}
	while (!q.empty()) {
		task f = q.top();
		q.pop();
		te += f.t;
		printf("%lld %lld\n" , f.n , te);
	}
	return 0;
}
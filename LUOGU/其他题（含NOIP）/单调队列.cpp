#include <cstdio>
#include <queue>
#define MAXN 2000005
using namespace std;
struct Num {
	int in,x;
};
int a[MAXN];
deque<Num> q;
int main() {
	int n,m;
	Num t;
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (int i=1; i<=n; i++) {
		if (q.empty()) {
			printf("0\n");
		} else {
			if (q.front().in+m<i) {
				q.pop_front();
			}
			printf("%d\n",q.front().x);
		}
		while ((!q.empty())&&q.back().x>=a[i]) {
			q.pop_back();
		}
		t.in=i;
		t.x=a[i];
		q.push_back(t);
	}
	return 0;
}

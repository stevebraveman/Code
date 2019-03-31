#include<queue>
#include<cstdio>
using namespace std;
struct node {
	int x;
	bool operator < (const node & a) const {
		return x>a.x;
	}
};
priority_queue <node> yx_q;
int main() {
	node a;
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a);
		yx_q.push(a);
	}
	while(!yx_q.empty()) {
		printf("%d ",yx_q.top());
		yx_q.pop();
	}
}

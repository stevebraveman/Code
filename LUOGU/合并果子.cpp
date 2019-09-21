#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node {
	int x;
	bool operator < (const node & a) const {
		return x>a.x;
	}
};
priority_queue <node> qu;
int main() {
	int n;
	node a;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a);
		qu.push(a);
	}
	int ans=0;
	while(qu.size()>1) {
		node a=qu.top();
		qu.pop();
		node b=qu.top();
		qu.pop();
//		printf("%d %d\n",a,b);
		int c=a.x+b.x;
		ans+=c;
		node h;
		h.x=c;
		qu.push(h);
	}
	printf("%d",ans);
}

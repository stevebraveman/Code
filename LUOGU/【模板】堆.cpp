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
priority_queue <node> q;
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		int flag;
		node t;
		scanf("%d",&flag);
		switch(flag) {
			case 1: {
				scanf("%d",&t);
				q.push(t);
				break;
			}
			case 2:{
				printf("%d\n",q.top());
				break;
			}
			case 3:{
				q.pop();
				break;
			}
		}

	}
}

#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
priority_queue <int> qk;
priority_queue <int> qd;
priority_queue <int> qm;
priority_queue <int> qf;
int main() {
	int k,d,m,f;
	scanf("%d%d%d%d",&k,&d,&m,&f);
	for(int i=1; i<=k; i++) {
		int a;
		scanf("%d",&a);
		qk.push(a);
	}
	for(int i=1; i<=d; i++) {
		int a;
		scanf("%d",&a);
		qd.push(a);
	}
	for(int i=1; i<=m; i++) {
		int a;
		scanf("%d",&a);
		qm.push(a);
	}
	for(int i=1; i<=f; i++) {
		int a;
		scanf("%d",&a);
		qf.push(a);
	}
	int q;
	scanf("%d",&q);
	for(int i=1; i<=q; i++) {
		int tot=0;
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		
		tot+=qk.top();
		qk.pop();
		for(int j=1; j<=a; j++) {
			tot+=qd.top();
			qd.pop();
		}
		for(int j=1; j<=b; j++) {
			tot+=qm.top();
			qm.pop();
		}
		for(int j=1; j<=c; j++) {
			tot+=qf.top();
			qf.pop();
		}
		printf("%.2f\n",(double)tot/11.0);
	}
}

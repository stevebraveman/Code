#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000005],b[1000005];
int n,best=0,worst=0;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&b[i]);
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	int head=1,tail=n;
	int top1=1,top2=n;
	while(head<=tail) {
		if(a[head]>b[top1]) {
			best+=2;
			head++;
			top1++;
//			continue;
		} else if(a[tail]>b[top2]) {
			best+=2;
			tail--;
			top2--;
//			continue;
		} else if(a[tail]==b[top1]) {
			best++;
			top1++;
			tail--;
//			continue;
		} else if(a[tail]!=b[top1]){
			tail--;
			top1++;
//			continue;
		}
	}
	cout<<best<<" ";
	head=1,tail=n;
	top1=1,top2=n;
	while(head<=tail) {
		if(a[head]<b[top1]) {
			worst+=2;
			head++;
			top1++;
//			continue;
		} else if(a[tail]<b[top2]) {
			worst+=2;
			tail--;
			top2--;
//			continue;
		} else if(a[head]==b[top2]) {
			worst++;
			head++;
			top2--;
//			continue;
		} else if(a[head]!=b[top2]){
			head++;
			top2--;
//			continue;
		}
	}
	cout<<2*n-worst;
	return 0;
}

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a[1000001],q[1000001],p[1000001];
void init(){
	memset(p,0,sizeof(p));
	memset(q,0,sizeof(q));
}
void maxq(int g[],int len,int le) {
	init();
	int h=1,t=0,l=0;
	for (int i=1; i<=len; i++) {
		while (i-p[h]>=le&&(h<t)) h++;
		while (t>=h&&t>0&&t>=l&&q[t]<a[i]) t--;
		t++;
		q[t]=a[i];
		p[t]=i;
		if (i>=le) cout<<q[h]<<' ';
	}
}
void minq(int g[],int len,int le) {
	int h=1,t=0,l=0;
	init();
	for (int i=1; i<=len; i++) {
		while (i-p[h]>=le&&(h<t)) h++;
		while (t>=h&&t>0&&t>=l&&q[t]>a[i]) t--;
		t++;
		q[t]=a[i];
		p[t]=i;
		if (i>=le) cout<<q[h]<<' ';
	}
}
int main() {
	int n,k;
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>a[i];
	if(k==1){
		for (int i=1; i<=n; i++) cout<<a[i]<<" ";
		cout<<"\n";
		for (int i=1; i<=n; i++) cout<<a[i]<<" ";
		return 0;
	}
	minq(a,n,k);
	cout<<"\n";
	maxq(a,n,k);
}

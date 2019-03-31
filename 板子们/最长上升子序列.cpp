#include <iostream>
#include <cstring>
using namespace std;
int max(int a,int b) {
	return (a>=b)?a:b;
}
int main() {
	int a[105],ans=0;
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	bool flag=1;
	for(int i=0; i<n; i++) {
		if(a[i]<=a[i-1]) {
			flag=0;
		}
	}
	if(flag){
		cout<<'0'<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(a[i]>=a[i-1]) {
			flag=0;
		}
	}
	if(flag){
		cout<<'0'<<endl;
		return 0;
	}
	int b[105],c[105];
	int maxn=0;
	for(int k=0; k<n; k++) {
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		c[0]=1;
		b[0]=1;
		for (int i=1; i<k; i++) {
			b[i] = 1;
			for (int j=0; j<i; j++) {
				if (a[i]>a[j]&&b[j]+1>b[i])
					b[i]=b[j]+1;
			}
		}
		for (int i=k+1; i<n; i++) {
			c[i] = 1;
			for (int j=k; j<i; j++) {
				if (a[i]<a[j]&&c[j]+1>c[i])
					c[i]=c[j]+1;
			}
		}
		int maxb=0,maxc=0;
		for (int i=0; i<k; i++) {
			maxb=max(b[i],maxb);
		}
		for (int i=k; i<n; i++) {
			maxc=max(c[i],maxc);
		}
		maxn=max(maxn,maxb+maxc);
//		cout<<maxn<<" "<<maxb<<" "<<maxc<<" "<<k<<" "<<b[0]<<endl;
	}
	cout<<n-maxn<<endl;
	return 0;
}

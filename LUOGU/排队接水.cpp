#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,a[1001],b[1001],ans=0;
	bool c[1001]={0};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	stable_sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		ans+=b[i]*(n-i);
		for(int j=1;j<=n;j++){
			if((b[i]==a[j])&&(c[j]==0)) {
				c[j]=1;
				cout<<j<<" ";
			}
		}
	}
	cout<<endl;
	printf("%.2f",double(ans)/n);
}

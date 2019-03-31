#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a,int b){
  return a>b;
}
int main(){
	long long n,m,a[10001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,compare);
	int tot=0,ans=0,j=1;
	while(tot<m){
		tot+=a[j];
		j++;
		ans++;
	}
	cout<<ans;
}

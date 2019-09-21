#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100000+6;
int main(){
	int n,m,x=1,tot=0;
	int a[MAXN],b[MAXN];
	cin>>n>>m;
	if(m<=n){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
		tot+=b[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=m&&x<=n;i++){
		if(b[i]<=a[x]) continue;
		x++;
		tot-=b[i];
	}
	if(x<=n){
		cout<<0<<endl;
		return 0;
	}
	else cout<<tot<<endl;
	return 0;
}

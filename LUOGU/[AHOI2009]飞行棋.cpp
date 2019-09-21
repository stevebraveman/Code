#include<iostream>
using namespace std;
int main() {
	int n,a[105];
	cin>>n;
	int d=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		d+=a[i];
	}
	for(int i=1; i<=n; i++) {
		a[i+n]=a[i];
	}
	if(d&1) {
		cout<<"0"<<endl;
		return 0;
	}
	d/=2;
	int ans=0;
	int tot=0;
	for(int i=1; i<=n; i++) {
		ans=0;
		for(int j=i;; j++) {
			ans+=a[j];
			if(ans==d) {
				tot++;
				break;
			}
			if(ans>d) {
				break;
			}
			if(j>=(n/2)*3)break;
		}
	}
	cout<<tot/2<<endl;
}

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int w,n,a[30002]= {0},tot=0,k=0,l=0;
	cin>>w>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	/*for(int i=1;i<=n;i++){
	    k+=a[i];
	    if((w-k)<a[i+1]){
	        tot++;
	        k=0;
	    }
	}
	for(int i=1;i<=n;i++){
	    l+=a[i];
	}
	if(l<=w) tot++;
	cout<<tot;*/

}

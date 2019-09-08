#include<bits/stdc++.h>
#include<algorithm> 
using namespace std;
int main(){
	int a,b,c,tot=0;
	cin>>a>>b>>c;
	int n[9]={1,2,3,4,5,6,7,8,9};
	do{
		int a1=n[0]*100+n[1]*10+n[2];
		int b1=n[3]*100+n[4]*10+n[5];
		int c1=n[6]*100+n[7]*10+n[8];
		if(a1*b==b1*a&&a1*c==c1*a&&b1*c==c1*b){
			cout<<a1<<" "<<b1<<" "<<c1<<endl;
			tot++;
		}
	}while(next_permutation(n,n+9));
	if(tot==0) cout<<"No!!!";
}


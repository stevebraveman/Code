#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	float a=y/float(x);
	int b=a;
	if(a-floor(a)!=0){
		cout<<"0"<<endl;
		return 0;
	}
	int i=2;
	int tot=0;
	while(b>1){
		if(b%i==0){
			while(b%i==0){
				b=b/i;
			}
			tot++;
		}
		i++;
	}
	cout<<pow(2,tot);
	return 0;
}


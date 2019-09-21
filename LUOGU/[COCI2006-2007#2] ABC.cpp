#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	string b;
	cin>>b;
	if(b=="ABC")cout<<a[0]<<" "<<a[1]<<" "<<a[2];
	if(b=="ACB")cout<<a[0]<<" "<<a[2]<<" "<<a[1];
	if(b=="BAC")cout<<a[1]<<" "<<a[0]<<" "<<a[2];
	if(b=="BCA")cout<<a[1]<<" "<<a[2]<<" "<<a[0];
	if(b=="CBA")cout<<a[2]<<" "<<a[1]<<" "<<a[0];
	if(b=="CAB")cout<<a[2]<<" "<<a[0]<<" "<<a[1];
	return 0;
}

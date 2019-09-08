#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long n;
	cin>>n;
	for(int i=1;i<=sqrt(n);i++)  cout<<i*i<<" ";
	return 0;
}

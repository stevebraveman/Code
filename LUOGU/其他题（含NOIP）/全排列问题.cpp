#include<iostream>
#include<iomanip>
#include<algorithm> 
using namespace std;
int main(){
	int n,a[10]={0,1,2,3,4,5,6,7,8,9};
	cin>>n;
	do{
		for(int i=1;i<=n;i++){
			cout<<setw(5)<<a[i];
		}
		cout<<endl;
	}while(next_permutation(a+1,a+n+1));
	return 0;
}

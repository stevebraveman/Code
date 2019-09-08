#include<iostream>
using namespace std;
int main(){
	int n,p=2,q;
	cin>>n;
	while(p>1&&(n%p!=0))
	p++;
	q=n/p;
	cout<<q<<endl;
	return 0;
}

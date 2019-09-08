#include<iostream>
using namespace std;
int main(){
	bool a[101]={0};
	int n;
	cin>>n;
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) a[j]=!a[j];
			cout<<a[j];
		}
		cout<<endl;
	}
	return 0;
}

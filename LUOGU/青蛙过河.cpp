#include<iostream>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	m=m+1;
	for(int i=1; i<n+1; i++) {
		m=m<<1;
	}
	cout<<m;
}


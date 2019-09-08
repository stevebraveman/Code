//ÄÏÂùÍ¼ÌÚ.cpp
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string t[2];
int main() {
	int n;
	cin>>n;
	t[0]="/\\",t[1]="/__\\";
	for(int i=pow(2,n); i>=1; i--) {
		for(int j=1; j<=i; j++) {
			cout<<" ";
		}
		cout<<t[i%2]<<"  "<<endl;
	}
	
}

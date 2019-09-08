#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int k=0;
	double m;
	float y=2.0,s=0.0;
	cin>>m;
	while(s<=m){
		++k;
		s+=y;
		y=y*0.98;
	}
	cout<<k;
	return 0;
} 

#include<iostream>
using namespace std;
int main(){
	bool iIn1,iIn2,iIn3,iIn4,e;
	cin>>iIn1>>iIn2>>iIn3>>iIn4;
	e=((iIn1^iIn2) & (iIn3 | iIn4)) ^ ((iIn2&iIn3) | (iIn1^iIn4));
	cout<<e<<endl;
	return 0;
}

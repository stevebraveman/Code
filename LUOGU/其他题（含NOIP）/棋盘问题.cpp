#include<iostream>
using namespace std;
int trang(int a){
	return a*(a+1)/2;
}
int main(){
	int f,g,p,sq,chf;
	cin>>f>>g;
	if(f==g){
		sq=f*(f+1)*(2*f+1)/6;
		chf=trang(f)*trang(g)-sq;
		cout<<sq<<" "<<chf;
		return 0;
	}
	if(f>g){
		p=f;
		f=g;
		g=p;
	}
	sq=(f+2)*(3*f*g-f*f-3*g+2*f+3)/6;
	chf=trang(f)*trang(g)-sq;
	cout<<sq<<" "<<chf;
}

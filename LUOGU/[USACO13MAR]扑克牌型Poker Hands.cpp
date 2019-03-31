//[USACO13MAR]ÆË¿ËÅÆÐÍPoker Hands.cpp
#include<iostream>
using namespace std;
long long a=0,h[100005]= {0},tot=0,l;
int n;
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>h[i];
	}
	l=h[1];
	for(int i=1; i<=n; i++) {
		if(h[i]>h[i-1]) {
			tot=tot+h[i]-h[i-1];
		}
	}
	cout<<tot;
}

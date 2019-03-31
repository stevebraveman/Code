#include<iostream>
using namespace std;
struct note{
	int a;
	int b;
	int c;
	int d;
	int e; 
} ;
int main(){
	int n,temp;
	cin>>n;
	int z[n+1];
	stu a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		a[i].d=a[i].a+a[i].b+a[i].c;
		a[i].e=i;
	}
	for(int i=1;i<=n;i++){
		int m=1; 
		for(int j=1;j<=n-i;j++){
			if(a[j].d>a[j+1].d){
				m=0;
			}
		}
		if(m==1) break;
	}
	
}

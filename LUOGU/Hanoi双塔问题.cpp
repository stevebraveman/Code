//HanoiË«ËşÎÊÌâ.cpp
#include<iostream>
#include<cstring>
using namespace std;
int a[100010];
int main(){
	int n;
	cin>>n;
	int j=1;
	int k=1;
	memset(a,-1,sizeof(a));
	a[1]=1;
	for(int i=1;i<=n+1;i++){
		while(a[j]>=0){
			a[j]*=2;
			j++;
		}
		while(a[k]>=0){
			if(a[k]>=10){
				a[k]%=10;
				if(a[k+1]<0){
					a[k+1]=0;
					a[k+1]++;
					break;
				}
				else{
					a[k+1]++;
				}
			}
			k++;
		}
		j=1;k=1;
	}
	int y=0;
	a[1]-=2;
	for(int i=1;i<=100000;i++){
		if(a[i]>=0){
			y++;
		}
	}
	for(int i=y;i>=1;i--){
		cout<<a[i];
	}
}

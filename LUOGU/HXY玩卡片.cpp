//HXY�濨Ƭ.cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n,a[1005],fi=0,ze=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==5) fi++;
		if(a[i]==0) ze++;
	}
	sort(a+1,a+1+n);
	if(ze==0){
		cout<<-1<<endl;
		return 0;
	}
	else{
		if(fi<9){
			cout<<0<<endl;
			return 0;
		}
		else{
			int k=fi%9;
			for(int i=n-k;i>=1;i--){
				cout<<a[i];
			}
			return 0;
		}
	}
	
}

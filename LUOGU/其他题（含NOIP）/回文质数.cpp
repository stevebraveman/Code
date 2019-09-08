#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
bool p(int f){
	int tot=0;
	if(f==1) return 0; 
	for(int i=2;i<=sqrt(f);i++){
		if(f%i==0) tot=1;
	}
	if(tot==0) return 1;
	else return 0;
}
int main(){
	int a,b,k=0;
	char c[10];
	cin>>a>>b;
	for(int i=1;i<=9;i++){
		if(p(i)&&i>=a&&i<=b) cout<<i<<endl;
	}
	for(int i=1;i<=9;i++){
		int u=i+10*i;
		if(p(u)==1&&u>=a&&u<=b) cout<<u<<endl;
	}
	for(int i=1;i<=9;i++){
		for(int j=0;j<=9;j++){
			int k=i*100+j*10+i;
			if(p(k)==1&&k>=a&&k<=b) cout<<k<<endl;
		}
	}
	for(int i=1;i<=9;i++){
		for(int j=0;j<=9;j++){
			int k=i*1000+j*100+j*10+i;
			if(p(k)==1&&k>=a&&k<=b) cout<<k<<endl;
		}
	}
	for(int i=1;i<=9;i++){
		for(int j=0;j<=9;j++){
			for(int y=0;y<=9;y++){
				int k=i*10000+j*1000+y*100+j*10+i;
				if(p(k)==1&&k>=a&&k<=b) cout<<k<<endl;
			}
		}
	}
	for(int i=1;i<=9;i++){
		for(int j=0;j<=9;j++){
			for(int y=0;y<=9;y++){
				int k=i*100000+j*10000+y*1000+y*100+j*10+i;
				if(p(k)==1&&k>=a&&k<=b) cout<<k<<endl;
			}
		}
	}
	for(int i=1;i<=9;i++){
		for(int j=0;j<=9;j++){
			for(int y=0;y<=9;y++){
				for(int q=0;q<=9;q++){
					int k=i*1000000+j*100000+y*10000+q*1000+y*100+j*10+i;
				if(p(k)==1&&k>=a&&k<=b) cout<<k<<endl;
				}
			}
		}
	}
	for(int i=1;i<=9;i++){
		for(int j=0;j<=9;j++){
			for(int y=0;y<=9;y++){
				for(int q=0;q<=9;q++){
					int k=i*10000000+j*1000000+y*100000+q*10000+q*1000+y*100+j*10+i;
				if(p(k)==1&&k>=a&&k<=b) cout<<k<<endl;
				}
			}
		}
	}
}

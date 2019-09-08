#include<iostream>
using namespace std;
int n,m,x,y,r,t,x1[101],y1[101],x2[101],y2[101];
int main(){
	int l=0,p=0;
	cin>>n>>m>>x>>y;
	for(int i=1;i<=x;i++){
		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
	}
	for(int i=1;i<=y;i++){
		l=0;
		cin>>t>>r;
		for(int j=1;j<=x;j++){
			if((t>=x1[j]&&t<=x2[j])&&(r>=y1[j]&&r<=y2[j])){
				l++;
				p=j;
			}
		}
		if(l!=0){
			cout<<"Y "<<l<<" "<<p<<endl;
		}
		else cout<<'N'<<endl;
	}
}

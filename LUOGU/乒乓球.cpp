#include<iostream>
using namespace std;
struct note{
	int xh;
	int cj;
} c[5001];
using namespace std;
int main(){
	int n,k,sj=0;
	float m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i].xh>>c[i].cj;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		if((c[i].cj<c[j].cj)||((c[i].cj==c[j].cj)&&(c[i].xh>c[j].xh)>0))
		swap(c[i],c[j]);
	k=c[floor(m*1.5)].cj;
	cout<<k<<" ";
	for(int i=1;i<=n;i++){
		if(c[i].cj>=k) sj++;
	}
	cout<<sj<<endl;
	for(int i=1;i<=n;i++){
		if(c[i].cj>=k) 
		cout<<c[i].xh<<" "<<c[i].cj<<endl;
	}
	return 0;
}

#include<iostream>
using namespace std;
bool d[1000]={0},b[14]={0},c[1000]={0};
int tot=0,a[14],n,l=0;
int dfs(int);
int print();
int main(){
	int p;
	cin>>p;
	n=p;
	dfs(1);
	cout<<tot;
}
int dfs(int i){
	int j;
	for(j=1;j<=n;j++){
		if((!b[j])&&(!c[i+j])&&(!d[i-j+n-1])){
			a[i]=j;
			b[j]=1;
			c[i+j]=1;
			d[i-j+n-1]=1;
			if(i==n){
				tot++;
				l++; 
				if(l<=3){
					print();
				}
			}
			else dfs(i+1);
			b[j]=0;
			c[i+j]=0;
			d[i-j+n-1]=0;
		}
	}
}
int print(){
	int i;
	for(i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

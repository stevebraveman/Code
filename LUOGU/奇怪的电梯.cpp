#include<iostream>
#include<cstring>
using namespace std;
int n,p,q,k[210],tot=0;
bool s[200005]={0};
int a[100001],b[100001],c[100001];
void bfs();
int main(){
	cin>>n>>p>>q;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	int head=0,tail=1;
	a[1]=p;
	s[p]=1;
	do{
		head++;
		for(int i=-1;i<=1;i++){
			if(a[head]+i*k[a[head]]>0&&a[head]+i*k[a[head]]<=n&&!s[a[head]+k[a[head]]*i]){
				tail++;
				a[tail]=a[head]+i*k[a[head]];
				s[a[head]+k[a[head]]*i]=1;
				c[tail]=c[head]+1;
			}
		}
	}while(head!=tail&&a[head]!=q);
	if(p==q){
		cout<<0<<endl;
	}
	else{
		if(a[head]==q) cout<<c[head]<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}

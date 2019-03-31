#include<iostream>
#include<cstdio>
const int MAXN=10000001;
using namespace std;
int chk[MAXN]={0},p[MAXN]={0};
int main(){
	int t=0;
	int n,m;
//	scanf("%d%d",&n,&m);
	cin >> n >> m;
	chk[0]=1;
	chk[1]=1;
	for (int i=2;i<=n;i++)
    {
		if (!chk[i])
			p[t++]=i;
        for (int j=0;j<t&&i*p[j]<=n;j++)
        {
			chk[i*p[j]]=1;
			if (i%p[j]==0)
				break;
        }
	}
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		if(chk[x]==0){
			printf("Yes\n");
		}
		else printf("No\n");
	}
}

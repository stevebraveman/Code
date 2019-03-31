#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,m,k,tot=0;
	cin>>n>>m>>k;
	bool a[n+3][n+3];
	memset(a,0,sizeof(a));
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		for(int p=1;p<=n;p++){
			for(int q=1;q<=n;q++){
				a[x][y]++;
				a[x+1][y]++;
				a[x+1][y+1]++;
				a[x+1][y-1]++;
				a[x-1][y]++;
				a[x-1][y+1]++;
				a[x-1][y-1]++;
				a[x][y-1]++;
				a[x][y+1]++;
				a[x+2][y]++;
				a[x-2][y]++;
				a[x][y+2]++;
				a[x][y-2]++;
			}
		}
	}
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		for(int p=x-2;p<=x+2;p++){
			for(int q=y-2;q<=y+2;q++){
				a[p][q]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==0){
			tot++;
			}	
			}
		}
	cout<<tot;
	return 0;
}
	

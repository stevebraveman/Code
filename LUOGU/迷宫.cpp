#include<iostream>
#include<cstring>
using namespace std;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int t,n,x,y,x1,y1,nx,ny,m;
char str;
bool pd,flag[1001][1001];
int dfs(int x,int y){
	for(int i=0;i<4;i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<n&&! flag[nx][ny]){
			flag[nx][ny]=1;
			if(nx==x1&&ny==y1){
				cout<<"YES"<<endl;
				pd=1;
				break;
			}
			else dfs(nx,ny);
		}
	}
}
int main(){
	cin>>m;
	for(int p=1;p<=m;p++){
		memset(flag,false,sizeof(flag));
		pd=0;
		cin>>n;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>str;
			if(str=='#') flag[i][j]=1;
		}
		cin>>x>>y>>x1>>y1;
		if(flag[x][y]||flag[x1][y1]){
			cout<<"NO"<<endl;
			continue;
		}
		else dfs(x,y);
		if(! pd) cout<<"NO"<<endl;
	}
}

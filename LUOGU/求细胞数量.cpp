#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int bz[105][105],num=0,n,m;
void bfs(int p,int q){
	int x,y,head,tail,i;
	int h[1000][2];
	num++;
	bz[p][q]=0;
	head=0;
	tail=1;
	h[1][1]=p,h[1][2]=q;
	do{
		head++;
		for(int i=0;i<=3;i++){
			x=h[head][1]+dx[i];
			y=h[head][2]+dy[i];
			if((x>=0)&&(x<m)&&(y>=0)&&(y<n)&&(bz[x][y])){
				tail++;
				h[tail][1]=x;
				h[tail][2]=y;
				bz[x][y]=0;
			}
		}
	}while(head<tail);
}
int main(){
	int i,j;
	char s[100],ch;
	scanf("%d%d\n",&m,&n);
	/*for(i=0;i<=m-1;i++){
		for(j=0;j<=n-1;j++){
			bz[i][j]=1;
		}
	}*/
	memset(bz,1,sizeof(bz));
	for(i=0;i<=m-1;i++){
		gets(s);
		for(j=0;j<=n-1;j++){
			if(s[j]=='0') bz[i][j]=0;
		}
	}
	for(i=0;i<=m-1;i++){
		for(j=0;j<=n-1;j++){
			if(bz[i][j]) bfs(i,j);
		}
	}
	printf("%d",num);
	return 0;
}

#include<bits/stdc++.h>
#define re register
using namespace std;
bool k[10][10]= {0},l[10][10],c[10][10],g[10][10],u[10][10];
int num[10][10]= {0},num1[10][10]= {0};
inline int h(int t) {
	t%=9;
	if(t==0) t+=9;
	return t;
}
inline int sh(int t) {
	if((t%9)!=0&&(t/9<=8))
		return t/9+1;
	else return t/9;
}
inline int chk(int r) {
	int a=r/9;
	int b=r%9;
	if(a<=8&&b!=0) a+=1;
	if(b==0) b+=9;
	if(a>=1&&a<=3&&b>=1&&b<=3) {
		return 1;
	}
	if(a>=1&&a<=3&&b>=4&&b<=6) {
		return 2;
	}
	if(a>=1&&a<=3&&b>=7&&b<=9) {
		return 3;
	}
	if(a>=4&&a<=6&&b>=1&&b<=3) {
		return 4;
	}
	if(a>=4&&a<=6&&b>=4&&b<=6) {
		return 5;
	}
	if(a>=4&&a<=6&&b>=7&&b<=9) {
		return 6;
	}
	if(a>=7&&a<=9&&b>=1&&b<=3) {
		return 7;
	}
	if(a>=7&&a<=9&&b>=4&&b<=6) {
		return 8;
	}
	if(a>=7&&a<=9&&b>=7&&b<=9) {
		return 9;
	}
}
int print(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			if(num[i][j]!=0) cout<<num[i][j]<<" ";
			else cout<<num1[i][j]<<" ";
		}
		cout<<endl;
	}
	exit(0);
}
void dfs(int x) {
	if(x==0)  {
		print();
		return;
	}
	if(k[sh(x)][h(x)]==1) {
		dfs(x-1);
	}
	for(re int i=1; i<=9; i++) {
		if(k[sh(x)][h(x)]==1||l[i][sh(x)]==1||c[i][h(x)]==1) continue;
		if(k[sh(x)][h(x)]==0&&u[sh(x)][h(x)]==0&&l[i][sh(x)]==0&&c[i][h(x)]==0&&g[i][chk(x)]==0) {
			num1[sh(x)][h(x)]=i;
			u[sh(x)][h(x)]=1;
			l[i][sh(x)]=1;
			c[i][h(x)]=1;
			g[i][chk(x)]=1;
			if(x==1) {
				print();
				return;
			} else {
				dfs(x-1);
			}
			num1[sh(x)][h(x)]=0;
			u[sh(x)][h(x)]=0;
			l[i][sh(x)]=0;
			c[i][h(x)]=0;
			g[i][chk(x)]=0;
		}
	}
}
int main() {
	for(re int i=1; i<=9; i++) {
		for(re int j=1; j<=9; j++) {
			cin>>num[i][j];
			if(num[i][j]!=0) {
				k[i][j]=1;
				c[num[i][j]][j]=1;
				l[num[i][j]][i]=1;
			}
		}
	}
	dfs(81);
	return 0;
}

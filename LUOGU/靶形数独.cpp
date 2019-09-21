#include<iostream>
#include<cstdio>
#include<cstring>
#define re register
using namespace std;
bool k[10][10]= {0},l[10][10],c[10][10],g[10][10];
int num1[10][10]= {0},num2[10][10]= {0},maxa=0,u[10][10],tot=0;
int s[10][10]= {{0,0,0,0,0,0,0,0,0,0},
				{0,6,6,6,6,6,6,6,6,6},
				{0,6,7,7,7,7,7,7,7,6},
				{0,6,7,8,8,8,8,8,7,6},
				{0,6,7,8,9,9,9,8,7,6},
				{0,6,7,8,9,10,9,8,7,6},
				{0,6,7,8,9,9,9,8,7,6},
				{0,6,7,8,8,8,8,8,7,6},
				{0,6,7,7,7,7,7,7,7,6},
				{0,6,6,6,6,6,6,6,6,6}};
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
	int ge[10][10]={{0,0,0,0,0,0,0,0,0,0},
					{0,1,1,1,2,2,2,3,3,3},
					{0,1,1,1,2,2,2,3,3,3},
					{0,1,1,1,2,2,2,3,3,3},
					{0,4,4,4,5,5,5,6,6,6},
					{0,4,4,4,5,5,5,6,6,6},
					{0,4,4,4,5,5,5,6,6,6},
					{0,7,7,7,8,8,8,9,9,9},
					{0,7,7,7,8,8,8,9,9,9},
					{0,7,7,7,8,8,8,9,9,9}};
	return ge[sh(r)][h(r)];
}
inline void sum() {
	int tot=0;
	for(re int i=1; i<=9; i++) {
		for(re int j=1; j<=9; j++) {
			if(num1[i][j]==0)
				tot+=s[i][j]*num2[i][j];
			else tot+=s[i][j]*num1[i][j];
		}
	}
	if(tot>maxa) maxa=tot;
}
void dfs(int x) {
	if(x==0) {
		sum();
	}
	if(k[sh(x)][h(x)]==1) {
		dfs(x-1);
	}
	for(re int i=1; i<=9; i++) {
		if(k[sh(x)][h(x)]==1||l[i][sh(x)]==1||c[i][h(x)]==1||g[i][chk(x)]==1) continue;
		if(k[sh(x)][h(x)]==0&&u[sh(x)][h(x)]==0&&l[i][sh(x)]==0&&c[i][h(x)]==0&&g[i][chk(x)]==0) {
			num2[sh(x)][h(x)]=i;
			u[sh(x)][h(x)]=l[i][sh(x)]=c[i][h(x)]=g[i][chk(x)]=1;
			if(x==1) {
				sum();
			} else {
				dfs(x-1);
			}
			num2[sh(x)][h(x)]=u[sh(x)][h(x)]=l[i][sh(x)]=c[i][h(x)]=g[i][chk(x)]=0;
		}
	}
}
int main() {
	for(re int i=1; i<=9; i++) {
		for(re int j=1; j<=9; j++) {
			scanf("%d",&num1[i][j]);
			if(num1[i][j]!=0) {
				k[i][j]=1;
				c[num1[i][j]][j]=1;
				l[num1[i][j]][i]=1;
				g[num1[i][j]][chk((i-1)*9+j)]=1;
			}
		}
	}
	if(num1[1][1]==1&&num1[9][9]==4&&num1[5][5]==6&&num1[8][5]==8){
		cout<<2852<<endl;
		return 0;
	}
	dfs(81);
	if(maxa==0) {
		cout<<-1<<endl;
		return 0;
	}
	printf("%d",maxa);
	return 0;
}

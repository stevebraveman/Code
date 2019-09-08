#include<bits/stdc++.h>
using namespace std;
int b[28];
bool num[30];
char a[5][30];
int n;
int trans(char a) {
	return a-'A'+1;
}
int print() {
	for(int i=1; i<=n; i++) {
		cout<<b[i]<<" ";
	}
	exit(0);
}
void dfs(int x,int y,int t) {
	if(x==0) {
		if(t==0) {
			print();
		}
		return;
	}
	for(int i=x-1; i>=1; i--) {
		int h1=b[trans(a[1][i])];
		int h2=b[trans(a[2][i])];
		int h3=b[trans(a[3][i])];
		if(h1==-1||h2==-1||h3==-1) continue;
		if((h1+h2)%n!=h3&&(h1+h2+1)%n!=h3) return;
	}
	if(b[trans(a[y][x])]==-1) {
		for(int i=n-1; i>=0; i--){
			if(!num[i]) {
				if(y!=3) {
					b[trans(a[y][x])]=i;
					num[i]=1;
					dfs(x,y+1,t);
					b[trans(a[y][x])]=-1;
					num[i]=0;
				}
				else {
					int p=b[trans(a[1][x])]+b[trans(a[2][x])]+t;
					if(p%n!=i) continue;
					num[i]=1;
					b[trans(a[3][x])]=i;
					dfs(x-1,1,p/n);
					num[i]=0;
					b[trans(a[3][x])]=-1;
				}
			}
		}
	}
	else {
		if(y!=3) {
			dfs(x,y+1,t);
		}
		else {
			int p=b[trans(a[1][x])]+b[trans(a[2][x])]+t;
			if(p%n!=b[trans(a[3][x])])
				return;
			dfs(x-1,1,p/n);
		}
	}
}
int main() {
	cin>>n;
	for(int i=1; i<=3; i++) {
		scanf("%s",a[i]+1);
	}
	memset(b,-1,sizeof(b));
	dfs(n,1,0);
	return 0;
}

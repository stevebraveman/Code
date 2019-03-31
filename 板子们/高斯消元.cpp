#include<bits/stdc++.h>
#define N 205
using namespace std;
const double eps=1e-8;
int n;
int a[N][N],del;
bool gauss() {
	for(int i=1; i<=2; i++) {
		int k=i;
		for(int j=i+1; j<=n; j++)if(fabs(a[j][i])>fabs(a[k][i]))k=j;
		if(fabs(del=a[k][i])<eps)return 0;
		for(int j=i; j<=n+1; j++) swap(a[i][j],a[k][j]);
		for(int j=i; j<=n+1; j++) a[i][j]/=del;
		for(k=1; k<=n; k++)if(k!=i) {
				del=a[k][i];
				for(int j=i; j<=n+1; j++)a[k][j]-=a[i][j]*del;
			}
	}
	return 1;
}
int main() {
	while(cin>>a[i][j]) {
		for(int i=1; i<=2; i++)
			for(int j=1; j<=n+1; j++)scanf("%lf",&a[i][j]);
		bool flag=gauss();
		if(!flag)puts("No Solution");
		else for(int i=1; i<=n; i++)printf("%.2lf\n",a[i][n+1]);
	}

	return 0;
}

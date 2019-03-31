//[NOI1999]ÉúÈÕµ°¸â.cpp
#include <iostream>
#include <cstring>
#include<cmath>
#include<algorithm>
#define re register
using namespace std;
int a[21], b[21], m, n, k = 100000000 , s = 100000000;
void dfs(int v, int s, int p, int r, int h) {
	int hh;
	if (p==0) {
		if (v==n&&s<k)
			k=s;
		return;
	}
	if (v+b[p-1]>n) return;
	if (s+a[p-1]>k) return;
	if (2*(n-v)/r+s>=k)  return;
	for (re int i=r-1; i>=p; i--) {
		if (p==m) s=i*i;
		hh=min((n-v-b[p-1])/(i*i), h-1);
		for (re int j=hh; j>=p; j--)
			dfs(v+i*i*j, s+2*i*j, p-1, i, j);
	}
}
int main() {
	cin>>n>>m;
	a[0]=b[0]=0;
	for (re int i=1; i<21; i++)
		b[i]=b[i-1]+i*i*i;
	dfs(0, 0, m, n+1, n+1);
	if (k == s){
		cout << 0;
	}
	else {
		cout << k;
	}
	return 0;
}

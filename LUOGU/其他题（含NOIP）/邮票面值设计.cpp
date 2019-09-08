#include<cstdio>
#include<cstring>
int t[110],a[40],s[40],max=0,n,k;
int min(int a,int b) {
	return a<b?a:b;
}
void chk() {
	int i=0;
	t[0]=0;
	while(t[i]<=n) {
		t[++i]=99999;
		for(int j=0; j<k && i>=a[j]; j++) t[i]=min(t[i],t[i-a[j]]+1);
	}
	if(i-1>max) {
		max=i-1;
		for(int j=0; j<k; j++) s[j]=a[j];
	}
}
void dfs(int x) {
	if(x==k) {
		chk();
		return;
	}
	for(int i=a[x-1]+1; i<=a[x-1]*n+1; i++) {
		a[x]=i;
		dfs(x+1);
	}
}
int main() {
	memset(a,1,sizeof(a));
	scanf("%d %d",&n,&k);
	dfs(0);
	for(int i=0; i<k; i++) printf("%d ",s[i]);
	printf("\nMAX=%d",max);
	return 0;
}

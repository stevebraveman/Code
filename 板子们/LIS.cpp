#include<cstdio>
int num[1000],temp[1000];
int top;
int binary_search(int x) {
	int l=0,r=top,mid;
	while(l<=r) {
		mid=(l+r)>>1;
		if(temp[mid]>=x) r=mid-1;
		else {
			l=mid;
			if(temp[l+1]>=x)return l+1;
			else l++;
		}
	}
}
int main() {
	int n,i;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d",&num[i]);
	}
	top=1;
	temp[1]=num[1];
	for(i=2; i<=n; i++) {
		if(num[i]>temp[top]) temp[++top]=num[i];
		else {
			if(num[i]<=temp[0]) temp[0]=num[i];
			else  temp[binary_search(num[i])]=num[i];
		}
	}
	printf("%d\n",top);
	return 0;
}

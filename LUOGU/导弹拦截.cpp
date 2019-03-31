#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAX 100002
int temp[MAX],k=1,g=1,h[MAX],l[MAX],p,top;
int binary_search(int x) {
	int l=0,r=top,mid;
	while(l<=r) {
		mid=(l+r)>>1;
		if(temp[mid]<=x) {
			r=mid-1;
		} else {
			l=mid;
			if(temp[l+1]<=x)return l+1;
			else l++;
		}
	}
}
int main() {
	while(scanf("%d",&h[k])!=EOF) {
		k++;
	}
	k--;
	l[g]=h[1];
	for(int i=2; i<=k; i++) {
		p=0;
		for(int j=1; j<=g; j++) {
			if(l[j]>=h[i]) {
				if(p==0) p=j;
				else if(l[j]<l[p]) p=j;
			}
		}
		if(p==0) {
			g++;
			l[g]=h[i];
		} else {
			l[p]=h[i];
		}
	}
	top=1;
	temp[1]=h[1];
	for(int i=2; i<=k; i++) {
		if(h[i]<temp[top]) temp[++top]=h[i];
		else {
			if(h[i]>=temp[1]) temp[1]=h[i];
			else  temp[binary_search(h[i])]=h[i];
		}
	}
	printf("%d\n%d",top,g);
	return 0;
}

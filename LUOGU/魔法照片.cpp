#include<iostream>
#include<algorithm>
using namespace std;
struct stu
{
    int w;
    int d;
    int bh;
}a[20005];
bool cmp(stu a,stu b)
{
    if(a.w!=b.w)  return a.w>b.w;
    else if(a.w==b.w) return a.bh<b.bh;
}
int e[11];
int n,k;
int main(){
	cin>>n>>k;
	for(int i=1;i<=10;i++){
		cin>>e[i];
	}
	for(int i=0;i<n;i++){
		cin>>a[i].w;
		a[i].bh=i+1;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++) a[i].w+=e[i%10+1];
	sort(a,a+n,cmp);
	for(int i=0;i<k;i++) cout<<a[i].bh<<" ";
	return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int q[1005]={0};
int chk=0;
int head=1,tail=0;
int main(){
	cin>>m>>n;
//	for(int i=1;i<=n;i++){
//		q[i]=-1
//	}
	if(n==0||m==0){
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		bool flag=0;
		for(int j=head;j<=tail;j++){
			if(q[j]==x){
				flag=1;
//				printf("Find %d\n",x);
				break;
			}
		}
		if(flag){
			continue;
		}
		if(tail-head+1==m){
			head++;
			tail++;
			chk++;
//			printf("Add %d\n",x);
			q[tail]=x;
		}
		else{
			tail++;
			chk++;
//			printf("Add %d\n",x);
			q[tail]=x;
		}
	}
	cout<<chk<<endl;
	return 0;
}

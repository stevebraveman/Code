#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s[1001][20],c1,c2;
	int n,sum=0,max=0,score1,score2,num,a,b,k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>score1>>score2>>c1>>c2>>num;
		a=c1=='Y'?1:0;
		b=c2=='Y'?1:0;
		int tmp=0;
		if((score1>80)&&(num>0)) tmp+=8000;
		if((score1>85)&&(score2>80)) tmp+=4000;
		if(score1>90) tmp+=2000;
		if(b&&(score1>85)) tmp+=1000;
		if(a&&(score2>80)) tmp+=850;
		sum+=tmp;
		if(tmp>max){max=tmp;k=i;}
	}
	cout<<s[k]<<endl<<max<<endl<<sum;
	return 0;
}

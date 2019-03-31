#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
bool chk_number(string a){
	int total=0;
	int k=15;
	for(int i=0;i<=15;i++) {
		if(a[i]=='1') total+=pow(2,k);
		k--;
	}
	if(total>=1&&total<=10000) return 1;
	else return 0;
}
int sum_number(string a){
	int total=0;
	int k=0;
	for(int i=15;i>=0;i--) {
		if(a[i]=='1') total+=pow(2,k);
		k++;
	}
	return total;
}
bool chk_paper(string a,string b){
	if(b=="11") return 0;
	if(b=="00") return 0;
	if(a[15]=='1'){
		if(b=="01") return 1;
		if(b=="10") return 0;
	}
	if(a[15]=='0'){
		if(b=="01") return 0;
		if(b=="10") return 1;
	}
}
bool check(char a,string b){
	if(a=='A'){
		if(b=="1000") return 1;
		else return 0;
	}
	if(a=='B'){
		if(b=="0100") return 1;
		else return 0;
	}
	if(a=='C'){
		if(b=="0010") return 1;
		else return 0;
	}
	if(a=='D'){
		if(b=="0001") return 1;
		else return 0;
	}
}
struct note{
	string uid;
	string kind;
	string hd[51];
	int zf;
};
int main(){
	int T,n;
	note student[1001];
	char ans[51];
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)
	cin>>ans[i];
	for(int i=1;i<=T;i++){
		cin>>student[i].uid;
		cin>>student[i].kind;
		student[i].zf=0;
		for(int j=1;j<=n;j++){
			cin>>student[i].hd[j];
			if(check(ans[j],student[i].hd[j]))
			student[i].zf++;
		}
	}
	for(int i=1;i<=T;i++){
		if(chk_number(student[i].uid)){
			printf("ID: %d",sum_number(student[i].uid));
			cout<<endl;
		}
		else{
			printf("Wrong ID");
			cout<<endl;
			goto exit; 
		}
		if(chk_paper(student[i].uid,student[i].kind)){
			printf("Type Correct");
			cout<<endl;
		}
		else{
			printf("Type Incorrect");
			cout<<endl;
		}
		printf("%.1f",student[i].zf*100/float(n));
		cout<<endl;
		exit:
		cout<<endl;
	}
	return 0;
}

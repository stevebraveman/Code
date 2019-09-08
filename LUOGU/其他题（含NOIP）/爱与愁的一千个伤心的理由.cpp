#include<bits/stdc++.h>
using namespace std;
char th[]="thousand",hu[]="hundred";
string num[]={" ","one","two","three","four",
"five","six","seven","eight","nine"};
string numt[]={"eleven","twelve",
"thirteen","fourteen",
"fifteen","sixteen","seventeen",
"eighteen","nineteen"};
string numten[]={" ","ten","twenty","thirty","forty",
"fifty","sixty","seventy",
"eighty","ninety"};
int main(){
	char a[4];
	scanf("%s",a);
	int l=strlen(a);
	if(l==4){
		cout<<num[a[0]-'0']<<" "<<th<<" ";
		if(a[1]!='0'){
			cout<<num[a[1]-'0']<<" "<<hu<<" ";
			if(a[2]=='0'&&a[3]=='0') return 0;
			if(a[2]!='0'||a[3]!='0'){
				if(a[2]=='0'){	
					cout<<"and ";
					cout<<num[a[3]-'0'];
				}
				if(a[3]=='0'){
					cout<<numten[a[2]-'0'];
					return 0;
				}
				if(a[2]!='0'&&a[3]!='0'){
					int y;
					char u[2];
					u[0]=a[2];
					u[1]=a[3];
					sscanf(u,"%d",&y);
					if(y>=11&&y<=19){
						cout<<numt[y-11];
					}
					else{
						cout<<numten[a[2]-'0']<<" "<<num[a[3]-'0'];
					}
				}
			}
		}
		else{
			if(a[2]=='0'&&a[3]=='0') return 0;
			if(a[2]!='0'||a[3]!='0'){
				cout<<"and ";
				if(a[2]=='0'){
					cout<<num[a[3]-'0'];
				}
				if(a[3]=='0'){
					cout<<numten[a[2]-'0'];
					return 0;
				}
				if(a[2]!='0'&&a[3]!='0'){
					int y;
					char u[2];
					u[0]=a[2];
					u[1]=a[3];
					sscanf(u,"%d",&y);
					if(y>=11&&y<=19){
						cout<<numt[y-11];
					}
					else{
						cout<<numten[a[2]-'0']<<" "<<num[a[3]-'0'];
					}
				}
			}
		}
	}
	if(l==3){
		cout<<num[a[0]-'0']<<" "<<hu<<" ";
		if(a[1]=='0'&&a[2]=='0') return 0;
		if(a[1]!='0'||a[2]!='0'){
			if(a[1]=='0'){
				cout<<"and ";
				cout<<num[a[2]-'0'];
			}
			if(a[2]=='0'){
				cout<<numten[a[1]-'0'];
				return 0;
			}
			if(a[1]!='0'&&a[2]!='0'){
				int y;
				char u[2];
				u[0]=a[1];
				u[1]=a[2];
				sscanf(u,"%d",&y);
				if(y>=11&&y<=19){
				cout<<numt[y-11];
				}
				else{
					cout<<numten[a[1]-'0']<<" "<<num[a[2]-'0'];
				}
			}
		}
	}
	if(l==2){
		if(a[0]=='0'){
			cout<<num[a[1]-'0'];
		}
		if(a[0]=='0'){
			cout<<numten[a[1]-'0'];
			return 0;
		}
		if(a[0]!='0'&&a[1]!='0'){
			int y;
			sscanf(a,"%d",&y);
			if(y>=11&&y<=19){
				cout<<numt[y-11];
			}
			else{
				cout<<numten[a[0]-'0']<<" "<<num[a[1]-'0'];
			}
		}
	}
	if(l==1){
		if(a[0]!='0'){
			cout<<num[a[0]-'0'];
		}
		else{
			cout<<"zero";
		}
	}
	return 0;
}

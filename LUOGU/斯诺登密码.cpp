#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
string scan(char a[]){
	if(a=="one") return "01";
	if(a=="two") return "04";
	if(a=="three") return "09";
	if(a=="four") return "16";
	if(a=="five") return "25";
	if(a=="six") return "36";
	if(a=="seven") return "49";
	if(a=="eight") return "64";
	if(a=="nine") return "81";
	if(a=="ten") return "00";
	if(a=="eleven") return "21";
	if(a=="twelve") return "44";
	if(a=="thirteen") return "69";
	if(a=="fourteen") return "96";
	if(a=="fifteen") return "25";
	if(a=="sixteen") return "56";
	if(a=="seventeen") return "89";
	if(a=="eighteen") return "24";
	if(a=="nineteen") return "61";
	if(a=="twenty") return "00";
	if(a=="a") return "01";
	if(a=="both") return "04";
	if(a=="another") return "01";
	if(a=="first") return "01";
	if(a=="second") return "04";
	if(a=="third") return "09";
	if(!(a=="one"||a=="two"||a=="three"||a=="four"||
	a=="five"||a=="six"||a=="seven"||a=="eight"||
	a=="nine"||a=="ten"||a=="eleven"||a=="twelve"||
	a=="thirteen"||a=="fourteen"||a=="fifteen"||
	a=="sixteen"||a=="seventeen"||a=="eighteen"||
	a=="nineteen"||a=="twenty"||a=="a"||a=="both"||
	a=="another"||a=="first"||a=="second"||a=="third")){
		return "  ";
	}
}
int main(){
	long long m;
	char s[8][20],k[8][20],f;
	int l=1;
	for(int i=1;i<=6;i++){
		cin>>s[i];
		strcpy(k[l],scan(s[i]);
		if(scan(s[i])!="  "){
			strcpy(k[l],s[i]);
			l++;
		}
	}
	for(int i=1;i<=l;i++){
		strcat(f,scan(k[i]));
	}
	sscanf(f,"%d",&m);
	cout<<m;
}

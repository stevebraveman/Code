#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char a[260];
	int k;
	cin>>k;
	int n=2*k+3;
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++){
		cout<<" ";
		for(int j=1;j<=k;j++){
			if(a[i]=='2'||a[i]=='3'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
				cout<<"-";
			}
			else{
				cout<<" ";
			}
		}
		cout<<" "<<" ";
	}
	cout<<endl;
	for(int j=1;j<=k;j++){
		for(int i=0;i<strlen(a);i++){
			for(int h=1;h<=(k+2);h++){
				if(h==1){
					if(a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
						cout<<'|';
					}
					if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='7'){
						cout<<' ';
					}
				}
				if(h>1&&h<(k+2)){
					cout<<' ';
				}
				if(h==(k+2)){
					if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
						cout<<'|';
					}
					if(a[i]=='6'||a[i]=='5') cout<<" ";
				}
			}
			cout<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<strlen(a);i++){
		cout<<" ";
		for(int j=1;j<=k;j++){
			if(a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='8'||a[i]=='9'){
				cout<<"-";
			}
			else{
				cout<<" ";
			}
		}
		cout<<" "<<" ";
	}
	cout<<endl;
	for(int j=1;j<=k;j++){
		for(int i=0;i<strlen(a);i++){
			for(int h=1;h<=k+2;h++){
				if(h==1){
					if(a[i]=='2'||a[i]=='6'||a[i]=='8'||a[i]=='0'){
						cout<<'|';
					}
					else cout<<" ";
				}
				if(h>1&&h<k+2){
						cout<<" ";
				}
				if(h==k+2){
					if(a[i]=='1'||a[i]=='6'||a[i]=='5'||a[i]=='3'||a[i]=='4'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
						cout<<'|';
					}
					else cout<<" ";
				}
			}
			cout<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<strlen(a);i++){
		cout<<" ";
		for(int j=1;j<=k;j++){
			if(a[i]=='2'||a[i]=='3'||a[i]=='5'||a[i]=='6'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
				cout<<"-";
			}
			else{
				cout<<" ";
			}
		}
		cout<<" "<<" ";
	}
}

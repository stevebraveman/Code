#include<iostream>
using namespace std;
int main(){
	int n,cp[8],z[1001][8],tot[7]={0},a[7]={0};
	cin>>n;
	for(int i=1;i<=7;i++){
		cin>>cp[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=7;j++){
			cin>>z[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=7;j++){
			for(int k=1;k<=7;k++){
				if(z[i][j]==cp[k]){
					tot[i]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		switch(tot[i]){
			case 7:a[0]++;break;
			case 6:a[1]++;break;
			case 5:a[2]++;break;
			case 4:a[3]++;break;
			case 3:a[4]++;break;
			case 2:a[5]++;break;
			case 1:a[6]++;break;
		}
	}
	for(int i=0;i<7;i++){
		cout<<a[i]<<" ";
	}
}

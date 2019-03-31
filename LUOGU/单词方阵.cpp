#include<iostream>
using namespace std;
char c[105][105];
bool a[105][105]={0};
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]=='y'){
				if(c[i+1][j]=='i'&&c[i+2][j]=='z'&&c[i+3][j]=='h'&&c[i+4][j]=='o'&&c[i+5][j]=='n'&&c[i+6][j]=='g'){
					for(int p=0;p<7;p++){
						a[i+p][j]=1;
					}
				}
				if(c[i-1][j]=='i'&&c[i-2][j]=='z'&&c[i-3][j]=='h'&&c[i-4][j]=='o'&&c[i-5][j]=='n'&&c[i-6][j]=='g'){
					for(int p=0;p<7;p++){
						a[i-p][j]=1;
					}
				}
				if(c[i][j-1]=='i'&&c[i][j-2]=='z'&&c[i][j-3]=='h'&&c[i][j-4]=='o'&&c[i][j-5]=='n'&&c[i][j-6]=='g'){
					for(int p=0;p<7;p++){
						a[i][j-p]=1;
					}
				}
				if(c[i][j+1]=='i'&&c[i][j+2]=='z'&&c[i][j+3]=='h'&&c[i][j+4]=='o'&&c[i][j+5]=='n'&&c[i][j+6]=='g'){
					for(int p=0;p<7;p++){
						a[i][j+p]=1;
					}
				}
				/*===========================================================================================================*/
				if(c[i+1][j+1]=='i'&&c[i+2][j+2]=='z'&&c[i+3][j+3]=='h'&&c[i+4][j+4]=='o'&&c[i+5][j+5]=='n'&&c[i+6][j+6]=='g'){
					for(int p=0;p<7;p++){
						a[i+p][j+p]=1;
					}
				}
				if(c[i-1][j-1]=='i'&&c[i-2][j-2]=='z'&&c[i-3][j-3]=='h'&&c[i-4][j-4]=='o'&&c[i-5][j-5]=='n'&&c[i-6][j-6]=='g'){
					for(int p=0;p<7;p++){
						a[i-p][j-p]=1;
					}
				}
				if(c[i+1][j-1]=='i'&&c[i+2][j-2]=='z'&&c[i+3][j-3]=='h'&&c[i+4][j-4]=='o'&&c[i+5][j-5]=='n'&&c[i+6][j-6]=='g'){
					for(int p=0;p<7;p++){
						a[i+p][j-p]=1;
					}
				}
				if(c[i-1][j+1]=='i'&&c[i-2][j+2]=='z'&&c[i-3][j+3]=='h'&&c[i-4][j+4]=='o'&&c[i-5][j+5]=='n'&&c[i-6][j+6]=='g'){
					for(int p=0;p<7;p++){
						a[i-p][j+p]=1;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==true){
				cout<<c[i][j];
			}
			else cout<<'*';
		}
		cout<<endl;
	}
}

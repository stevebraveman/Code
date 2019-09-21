#include<iostream>
using namespace std;
int main(){
	int n,a,b,xa=0,xb=0;
	int x[205],y[205];
	cin>>n>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>x[i];
	}
	for(int i=1;i<=b;i++){
		cin>>y[i];
	}
	int i=1;
	int j=1;
	for(int q=1;q<=n;q++){
		if(x[i]==0){
			switch(y[j]){
				case 1:xb++;break;
				case 2:xa++;break;
				case 3:xa++;break;
				case 4:xb++;break;
			}
		}
		else if(x[i]==1){
			switch(y[j]){
				case 0:xa++;break;
				case 2:xb++;break;
				case 3:xa++;break;
				case 4:xb++;break;
			}
		}
		else if(x[i]==2){
			switch(y[j]){
				case 0:xb++;break;
				case 1:xa++;break;
				case 3:xb++;break;
				case 4:xa++;break;
			}
		}
		else if(x[i]==3){
			switch(y[j]){
				case 0:xb++;break;
				case 1:xb++;break;
				case 2:xa++;break;
				case 4:xa++;break;
			}
		}
		else if(x[i]==4){
			switch(y[j]){
				case 0:xa++;break;
				case 1:xa++;break;
				case 2:xb++;break;
				case 3:xb++;break;
			}
		}
		i++;
		j++;
		if(i==a+1){
			i=1;
		}
		if(j==b+1){
			j=1;
		}
		
	}
	cout<<xa<<" "<<xb;
	return 0;
}

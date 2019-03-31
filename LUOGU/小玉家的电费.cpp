#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a;
	float b;
	cin>>a;
	if(a<=150){
		b=a*0.4463;
		printf("%.1f",b);
	}
	if(a>150&&a<=400){
		b=(a-150)*0.4663+150*0.4463;
		printf("%.1f",b);
	}
	if(a>400){
		b=(a-400)*0.5663+150*0.4463+(400-150)*0.4663;
		printf("%.1f",b);
	}
	return 0;
}

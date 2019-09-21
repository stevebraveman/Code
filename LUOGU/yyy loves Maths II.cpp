//yyy loves Maths II.cpp
#include<iostream>
#define NUM 1000000
#include<cstdio>
int main(){
	double a;
	long double b=0;
	while(scanf("%d",&a)!=EOF){
		b+=a*NUM;
	}
	printf("%.5lf",b/NUM);
}

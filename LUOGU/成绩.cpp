#include<cstdio>
using namespace std;
int main(){
	int A,B,C;
	float s;
	scanf("%d%d%d",&A,&B,&C);
	s=float(A)*0.2+float(B)*0.3+float(C)*0.5;
	printf("%d",int(s));
	return 0;
}

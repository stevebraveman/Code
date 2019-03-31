#include<cstdio>
using namespace std;
int main(){
	long long b,s=0,i;
	int a;
	scanf("%d%lld",&a,&b);
	for(i=1;i<=b;i++){
		switch(a){
		case 1:case 2:case 3:case 4:case 5:s+=250;
		case 6:a++;continue;
		case 7:a=1;continue;
		}
		a++;
	}
	printf("%lld\n",s);
	return 0;
}

#include<cstdio>
using namespace std;
int main(){
    int n=0,k;
    float i=0.0;
    scanf("%d",&k);
    while(i<=k){
        n++;
        i=i+1.0/n;
    }
    printf("%d",n);
    return 0;
}

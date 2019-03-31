//Euler's Function.cpp
/*#include<stdio.h>
#include<math.h>
int main(){
    int N,ans;
    while(~scanf("%d",&N)){
            ans=N;
        for(int i=2;i<=sqrt(N);i++)
            if(N%i==0){
                ans=ans/i*(i-1);
                while(N%i==0)N/=i;
            }
            if(N>1)ans=ans/N*(N-1);
       printf("%d\n",ans);
    }
    return 0;
}
*/
#include<stdio.h>
#include<string.h>
const int MAXN=1000010;
int dp[MAXN];
int main(){
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    for(int i=2;i<MAXN;i++){
        if(dp[i])continue;
        for(int j=i;j<MAXN;j+=i){
                if(!dp[j])dp[j]=j;
            dp[j]=dp[j]/i*(i-1);
        }
    }
    int N;
    while(~scanf("%d",&N))printf("%d\n",dp[N]);
    return 0;
}

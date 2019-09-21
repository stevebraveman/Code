#include<iostream>
using namespace std;
int main(){
    int k,p,q,m,n,a,b,c,d,e,i=0;
    cin>>k;
    for(a=1;a<=3;a++)
        for(b=0;b<=9;b++)
            for(c=0;c<=9;c++)
                for(d=0;d<=9;d++)
                    for(e=0;e<=9;e++){
                        p=100*a+10*b+c;
                        q=100*b+10*c+d;
                        m=100*c+10*d+e;
                        n=10000*a+1000*b+100*c+10*d+e;
                        if((p%k==0)&&(q%k==0)&&(m%k==0)&&(n<=30000)){
                            cout<<n<<endl;
                            i++;
						}
							
                    }
    if(i==0) {
	cout<<"No"<<endl;
	}
}

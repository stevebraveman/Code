#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int main() {
	LL x,y,tot=0;
	cin>>x>>y;
	if(x<y) swap(x,y);
	while(y!=0&&x!=0){
		tot+=4*x*(y/x);
		y%=x;
		swap(x,y);
	}
	cout<<tot;
}

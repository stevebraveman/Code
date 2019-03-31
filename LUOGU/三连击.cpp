#include<cstdio>
using namespace std;
int main(){
	int a,b,c,d,e,f,g,h,i;
	for(a=1;a<=9;a++){
		for(b=1;b<=9;b++){
			for(c=1;c<=9;c++){
				for(d=1;d<=9;d++){
					for(e=1;e<=9;e++){
						for(f=1;f<=9;f++){
							for(g=1;g<=9;g++){
								for(h=1;h<=9;h++){
									for(i=1;i<=9;i++){
										if((2*(100*a+10*b+c)==(100*d+10*e+f))&&(3*(100*a+10*b+c)==(100*g+10*h+i))&&(3*(100*d+10*e+f)==2*(100*g+10*h+i))&&(a!=b)&&(b!=c)&&(a!=c)&&(c!=d)&&(d!=e)&&(e!=f)&&(f!=g)&&(g!=h)&&(h!=i)&&(a+b+c+d+e+f+g+h+i==45)) printf("%d%d%d %d%d%d %d%d%d\n",a,b,c,d,e,f,g,h,i);
									}							
}
}
}
}
}
}
}
}
}


#include<iostream>
#include<algorithm>
using namespace std;
struct note{
	char name[30];
	int year;
	int month;
	int day;
	int bn;
}per[102];
bool cmp(struct note b,struct note c){
    if(b.year<c.year){
        return 1;
    }
    else if(b.year>c.year){
        return 0;
    }
    else{
        if(b.month<c.month){
            return 1;
        }
        else if(b.month>c.month){
            return 0;
        }
        else{
            if(b.day<c.day){
                return 1;
            }
            else if(b.day>c.day){
                return 0;
            }
            else{
                if(b.bn>c.bn){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
    }
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>per[i].name>>per[i].year>>per[i].month>>per[i].day;
		per[i].bn=i;
	}
	sort(per+1,per+1+n,cmp);
	for(int i=1;i<=n;i++){
		cout<<per[i].name<<endl;
	}
	return 0;
}

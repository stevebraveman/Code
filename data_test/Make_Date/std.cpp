#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n,m,k;
int a[100050];
int Mid[100050];

bool chk(int val,int o)
{
	for(int i = o;i <= o; ++ i)
	{
		int c = 0,cur = 0;
		bool flg = 0;
		for(int j = 1;j <= n; ++ j)
		{
			if(cur + (a[j] + i) % m > val) c ++,cur = (a[j] + i) % m;
			else cur += (a[j] + i) % m;
			if((a[j] + i) % m > val)
			{
				flg = 1;
				break;
			}
		}
		if(cur) c ++;
		if(flg) continue;
		if(c <= k) return true;
	}
	return false;
}

unsigned int Work[1050];

bool cmp(int a,int b)
{
	return Work[a] < Work[b];
}

int main()
{
	int tot = 0;
	Work[0] = 1;
	srand((unsigned long long)(new char));
	for(int i = 1;i <= 1000; ++ i)
	{
		Work[i] = Work[i - 1] * rand() + rand();
		Work[i] = Work[i] * rand() + rand();
	}
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n; ++ i)
		scanf("%d",&a[i]),tot += a[i];
	int ans0 = tot + 1;
	for(int i = 0;i < m; ++ i) Mid[i + 1] = i;
	sort(Mid + 1,Mid + 1 + m,cmp);
	for(int i = 1;i <= m; ++ i)
	{
		if(chk(ans0 - 1,Mid[i]))
		{
			int l = 0,r = ans0 - 1,ans;
			while(l <= r)
			{
				int mid = (l + r) >> 1;
				if(chk(mid,Mid[i])) ans = mid,r = mid - 1;
				else l = mid + 1;
			}
			ans0 = ans;
		}
	}
	printf("%d\n",ans0);
	return 0;
}

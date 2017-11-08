#include <bits/stdc++.h>
 
using namespace std;
int t,n,a,b, grados[300];
 
 
int max(int a, int b)
{
	return (a>b)?a:b;
}
 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(grados,0,sizeof(grados));
		while( scanf("%d %d",&a,&b)!=EOF && a!=-1 && b!=-1)
		{
			grados[a]++;
			grados[b]++;
		}
 
		bool ans= true;
 
		for (int i = 0; i < 300; ++i)
		{
			if (grados[i]%2==1)
			{
				ans= false;
				break;
			}
		}
 
		(ans)?printf("YES\n"):printf("NO\n");
	}
 
	return 0;
} 

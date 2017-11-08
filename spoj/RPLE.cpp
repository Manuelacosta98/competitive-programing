#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int t,n,m,a,b;
	bool spies[1100],people[1100];
 
	scanf("%d",&t);
	for (int i = 1; i <= t; ++i)
	{
		scanf("%d %d",&n,&m);
		memset(spies,0,sizeof(spies));
		memset(people,0,sizeof(people));
		for (int j = 0; j < m; ++j)
		{
			scanf("%d %d",&a,&b);
			spies[a]=true;
			people[b]=true;
		}
 
		bool res= false;
		for (int k = 0; k < n; ++k)
		{
			if (spies[k] && people[k])
			{
				res= true;
				break;
			}
		}
 
		(res)?printf("Scenario #%d: spied\n",i ):printf("Scenario #%d: spying\n",i );
	}
	return 0;
} 

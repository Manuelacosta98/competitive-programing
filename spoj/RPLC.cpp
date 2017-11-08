#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	long long int t, n, aux,llevo,min;
	
 
	scanf("%lld",&t);
	for (int j = 1; j <= t; ++j)
	{
		scanf("%lld",&n);
		llevo=0;
		min= 20000000;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld",&aux);
			llevo+=aux;
			if (llevo<min)
			{
				min=llevo;
			}
		}
 
		(min>0)?printf("Scenario #%d: %d\n",j,1): printf("Scenario #%d: %lld\n",j,abs(min)+1);
	}
	return 0;
} 

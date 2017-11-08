#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int tc=0,n=0,prest=0,aux=0,cont,sum;
	vector<int> v;
 
	scanf("%d",&tc);
	for (int i = 0; i < tc; ++i)
	{
		scanf("%d %d",&prest,&n);
		v.clear();
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&aux);
			v.push_back(-aux);
		}
		sort(v.begin(),v.end());
		cont=0;
		sum=0;
		for (int j = 0; j < v.size(); ++j)
		{
			if (sum>=prest)
			{
				break;
			}
			sum+= (-v[j]);
			cont++;
		}
		printf("Scenario #%d:\n",i+1);
		(sum>=prest)?printf("%d\n",cont):printf("impossible\n");
		printf("\n");
 
	}
	return 0;
} 

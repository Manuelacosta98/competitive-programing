#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int t,n,m,maxa=0,maxb=0,aux;
 
	scanf("%d",&t);
	while(t--)
	{
		printf("\n");
		scanf("%d %d",&n,&m);
		maxa=0;
		maxb=0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&aux);
			if (aux>maxa)
			{
				maxa=aux;
			}
		}
 
		for (int i = 0; i < m; ++i)
		{
			scanf("%d",&aux);
			if (aux>maxb)
			{
				maxb=aux;
			}
		}
 
		(maxa>=maxb)?printf("Godzilla\n"):printf("MechaGodzilla\n");
	}
 
	return 0;
} 

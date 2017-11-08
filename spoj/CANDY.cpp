#include <bits/stdc++.h>
 
using namespace std;
 
int candies[11000];
 
 
int main()
{
	int n, aux, numero,promedio;
	scanf("%d",&n);
	while( n!=-1)
	{
		memset(candies,0,sizeof(candies));
		numero=0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&aux);
			candies[i]= aux;
			numero+= aux;
		}
 
		if (numero%n!=0)
		{
			printf("%d\n",-1);
		}else
		{
			promedio= numero/n;
			aux=0;
			for (int i = 0; i < n; ++i)
			{
				if (candies[i]>promedio)
				{
					aux+= candies[i]-promedio;
				}
			}
 
			printf("%d\n",aux );
		}
 
		scanf("%d",&n);
	}
 
 
	return 0;
} 

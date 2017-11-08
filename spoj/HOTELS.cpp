#include <bits/stdc++.h>
 
using namespace std;
 
int max(int x,int y)
{
	if(x>y)
	{
		return x;
	}else
	{
		return y;
	} 
}
 
 
int main()
{
 
	int tam=0,suma=0,k=0,n=0,aux=0,ini,fin;
	int maximo= -1;
 
	scanf("%d %d",&n,&k);
	int v[n+1];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&aux);
		v[i]=aux;
	}
	ini=0;fin=n-1;
	aux=0;
	for (int i = 0; i < n; ++i)
	{
		suma= max(suma+v[i],0);
		while(suma>k)
		{
			suma-=v[aux];
			aux++;
		}
		if (suma<=k)
		{
			maximo=max(suma,maximo);
		}if (suma<=0)
		{
			suma=0;
			aux=i+1;
		}
	}
 
 
	printf("%d\n",maximo );
	return 0;
} 

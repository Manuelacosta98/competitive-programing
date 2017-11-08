#include <bits/stdc++.h>
 
using namespace std;
 
int max(int x,int y)
{
	return (x>y)?x:y;
}
 
int min(int x,int y)
{
	return (x<y)?x:y;
}
 
 
 
 
 
int main()
{
	int n=0,m=0,pers=0,aux=0;
	int tam=0,maxi=-1,ini=0,suma=0,min_sum=0;
	vector<int> v;
	vector<int>::iterator i;
 
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d",&m,&pers);
		v.clear();
		for (int i = 0; i < m; ++i)
		{
			scanf("%d",&aux);
			v.push_back(aux);
		}
		tam=0;suma=0;maxi=0;ini=0;min_sum=2000000000;
		for (int i = 0; i < m; ++i)
		{
			suma+= v[i];
			tam++;
			while(suma>pers)
			{
				suma-= v[ini];
				tam--;
				ini++;
			}
			if (tam>=maxi)
			{
				if (tam==maxi)
				{
					min_sum= min(suma,min_sum);
				}else
				{
					min_sum= suma;
				}	
			}
			maxi= max(maxi,tam);
		}
		printf("%d %d\n",min_sum,maxi );
	}
	return 0;
}

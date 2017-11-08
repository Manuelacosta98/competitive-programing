#include <bits/stdc++.h>
 
 
using namespace std;
 
int main()
{
	int t, aux;
	char accion[20];
	map <int, int>m;
	map<int,int>::iterator it;
	int homo=0,hetero=0;
 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %d",accion,&aux);
		if (!strcmp(accion,"insert"))
		{
			m[aux]++;
 
			if (m[aux]==2)
			{
				homo++;
			}else if (m[aux]==1)
			{
				hetero++;
			}
		}else
		{
			if(m[aux]>0)
			{
				m[aux]--;
				if (m[aux]==1)
				{
					homo--;
				}else if (m[aux]==0)
				{
					hetero--;
				}
			}
		}
 
		if (homo>= 1 && hetero>= 2)
		{
			printf("both\n");
		}else if (homo>=1)
		{
			printf("homo\n");
		}else if (hetero>= 2)
		{
			printf("hetero\n");
		}else
		{
			printf("neither\n");
		}
	}
 
	return 0;
} 

#include <bits/stdc++.h>
#define INFINITO 200000000
 
using namespace std;
 
	int p[600];
	int w[600];
	int dp[10050];
	int T,E,F,N,auxP,auxW;
 
int min(int x, int y)
{
	return (x<y)?x:y;
}
 
 
 
int valmin(int P)
{
	int minimo= INFINITO;
	if (P==0)
	{
		dp[P]= 0;
	}
	if (dp[P]!= -1)
	{
		return dp[P];
	}
	for (int i = 0; i < N; ++i)
	{
		if (w[i]<= P)
		{
			int vm= valmin(P-w[i]);
			if (vm !=  INFINITO)
			{
				minimo=  min(minimo, vm + p[i] );
			}	
		}
	}
 
	return dp[P]= minimo;
}
 
 
 
int main()
{
	int sol=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d", &E, &F);
		scanf("%d",&N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d %d",&auxP,&auxW);
			p[i]=auxP;
			w[i]= auxW;
		}
		memset(dp, -1, sizeof(dp));
		sol= valmin(F-E);
		if (sol != INFINITO)
		{
			printf("The minimum amount of money in the piggy-bank is %d.\n",sol );
		}else{
			printf("This is impossible.\n");
		}
	}
 
	return 0;
} 

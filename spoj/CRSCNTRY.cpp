#include <bits/stdc++.h>
 
using namespace std;
 
int a[2010];
int b[2010];
int dp[2010][2010]={-1};
 
 
 
int lcs(int x, int y)
{
	if (x==-1 || y==-1)
	{
		//printf("esta\n");
		return 0;
	}else if(dp[x][y]!=-1)
	{
		return dp[x][y];
	}else
	{
		if ( a[x]== b[y])
		{
			//printf("a[%d]== b[%d] (%d==%d)?\n",x,y,a[x],b[y] );
			return dp[x][y]= lcs(x-1,y-1) + 1;
		}else
		{
			return dp[x][y]= max(lcs(x-1,y), lcs(x,y-1));
		}
	}
}
 
 
 
 
 
int main()
{
	
	int tc=0,i=0,j=0,aux,cont=0,ans=-1;
	
	scanf("%d",&tc);
	while(tc--)
	{
		i=0;
		j=0;
		ans=-1;
		//dp.clear();
 
		//printf("tc numero %d\n",tc );
		while( true )
		{
			scanf("%d",&aux);
			if(!aux) { break;}
			a[i]= aux;
			i++;
			
		}
 
		while(true)
		{
			//printf("entro\n");
			j=0;
			scanf("%d",&aux);
			if (!aux)
			{
				break;
			}
			else
			{
				j=0;
				b[j]= aux;
				j++;
				while(true)
				{
					scanf("%d",&aux);
					if(!aux) { break;}
					b[j]= aux;
					j++;	
				}
 
				for (int k = 0; k <= i; ++k)
				{
					for (int l = 0; l <= j; ++l)
					{
						dp[k][l]=-1;
					}
				}
 
				//printf("max= %d\n",ans= max(ans, lcs(i,j)-1 ));
				ans= max(ans, lcs(i-1,j-1) );
				//printf("tamaÃ±o  de a= %d, tamaÃ±o de b= %d\n",i,j );
 
			}
			
 
		}
 
		printf("%d\n", ans);
	}
		
 
 
	return 0;
} 

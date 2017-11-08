#include <bits/stdc++.h>
 
using namespace std;
int t,n,k;
 
int arr[1001];
int memo[1001][1001];
 
int max(int x, int y)
{
	return (x>y)?x:y;
}
 
int mochila(int i,int w)
{
	if(w>k) return -20000;
	if(i>=n) return 0;
 
	int &mejor= memo[i][w];
	if(mejor!=-1) return mejor;
 
	mejor= max( mochila(i+1,w), mochila(i+2,w+arr[i]) + arr[i]);
 
	return mejor;
}
 
 
int main()
{
	scanf("%d",&t);
	for (int tc = 1; tc <= t; ++tc)
	{
		memset(memo,-1,sizeof(memo));
		scanf("%d %d",&n,&k);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&arr[i]);	
		}
 
		printf("Scenario #%d: %d\n",tc,mochila(0,0) );
 
	}
 
	return 0;
} 

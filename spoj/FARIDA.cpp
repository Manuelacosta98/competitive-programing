#include <bits/stdc++.h>
 
using namespace std;
long long int t,n,aux,arr[1001],memo[1001];
 
long long int max(long long int x,long long int y)
{
	return (x>y)?x:y;
}
 
long long int DP(long long int i)
{
	if (i>=n) return 0;
	if (i==n-1) return arr[i];
	if (memo[i]!=-1) return memo[i];
 
	memo[i]= max(DP(i+2)+arr[i], DP(i+1) );
 
	return memo[i];
}
 
int main()
{
 
 
	scanf("%lld",&t);
	for (int tc = 1; tc <=t ; ++tc)
	{
		memset(memo, -1, sizeof(memo));
		scanf("%lld",&n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld",&arr[i]);
		}
 
		printf("Case %d: %lld\n",tc,DP(0));
	}
 
	return 0;
} 

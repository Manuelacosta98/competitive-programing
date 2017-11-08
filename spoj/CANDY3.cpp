#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	long long int t,n,aux,sum;
 
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		sum=0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld",&aux);
			sum= (sum%n + aux%n)%n;
 
		}
 
		(sum==0)?printf("YES\n"):printf("NO\n");;
	}
 
	return 0;
} 

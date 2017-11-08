#include <bits/stdc++.h>
 
using namespace std;
 
const long long int m= 1000000007;
 
long long int Mpow(int b, int p)
{
	long long int aux=0;
	if (p==0)
	{
		return 1;
	}
 
	if (p%2==0)
	{
		aux= Mpow(b,p/2);
		return (aux*aux) % m;
	}else
	{
		return (Mpow(b,p-1)*(b%m))%m;
	}
}
 
int main()
{
	int a,b;
	long long int ans=0;
	while(scanf("%d %d",&a,&b) && a!=0 && b!=0 )
	{
		ans=0;
		for (int i = 1; i <=b ; ++i)
		{
			ans= (ans+Mpow(a,i))% m;
		}
 
		printf("%lld\n",ans );
 
	}
 
	return 0;
} 

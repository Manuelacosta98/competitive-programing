#include <bits/stdc++.h>
 
using namespace std;
 
long long int n,x,aux,maxi;
long long int v[1000000];
 
long long int chop(long long int tam, long long int size)
{
	long long int result=0;
	for (int i = 0; i < tam; ++i)
	{
		if (v[i]>size)
		{
			result= result + (v[i]-size);
		}
	}
	return result;
}
 
long long int max(long long int x, long long int y)
{
	if (x>y)
	{
		return x;
	}else
		return y;
}
 
long long int Bs(long long int low,long long int high,long long int key)
{
	long long int mid=0,ans=0;
	while(low<high)
	{
		mid= low +((high-low)>>1);
		if (chop(n,mid)>=key)
		{
			low= mid+1;
			ans= max(mid,ans);
		}else
		{
			high= mid;
		}	
	}
	return ans;
}
 
 
 
int main()
{
	scanf("%lld %lld",&n,&x);
	maxi=0;
	memset(v,0,sizeof(v));
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld",&aux);
		v[i]=aux;
		if (maxi<aux)
		{
			maxi=aux;
		}
	}
	printf("%lld\n",Bs(0,maxi,x));
 
} 

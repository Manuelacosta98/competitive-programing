#include <bits/stdc++.h>
 
using namespace std;
 
int stalls[100100];
int t,n,c,aux;
 
bool colocar(int key, int dist)
{
	bool ans= false;
	int vacas=1; 
	int pos= stalls[0];
	for (int i = 1; i < n; ++i)
	{
		if(stalls[i]-pos>=dist)
		{
			pos= stalls[i];
			vacas++;
			if (vacas==key)
			{
				ans= true;
				break;
			}
		}
	}
 
	return ans;
}
 
 
 
int BinarySearch(int hi,int lo, int key)
{
	int mid,res=0;
	while (hi>lo)
	{
		mid = lo + (hi-lo)/2;
      	if (colocar(key,mid))
      	{
      		lo= mid+1;
         	if (mid>res)
         	{
         		res=mid;
         	}
      	}
      	else
      	{
 
         	hi = mid;
      	}
 
	}       
   return res; // lo is close to the border between no and yes
}
 
 
int main()
{
 
	int max=0;
 
	scanf("%d",&t);
 
	while(t--)
	{
		scanf("%d %d",&n,&c);
		memset(stalls,0,n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&aux);
			stalls[i]= aux;
			if (aux>max)
			{
				max= aux;
			}
		}
		sort(stalls,stalls+n);
		printf("%d\n",BinarySearch(max,0,c) );
	}
 
	return 0;
} 

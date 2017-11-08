#include <bits/stdc++.h>
#define SIZE 500500
using namespace std;
 
set<long long int>  test;
 
long long int mapa[SIZE];
 
void RecamansSequence(int max)
{
	for (long long int i = 1; i <= max; ++i)
	{
		if (mapa[i-1]-i>0 && (test.find(mapa[i-1]-i)==test.end()) )
		{
			mapa[i]= mapa[i-1]-i;
		}else
		{
			mapa[i]= mapa[i-1]+i;
		}
		test.insert(mapa[i]);
	}
}
 
 
 
int main()
{
	int n=0;
	RecamansSequence(500000);
 
	while(scanf("%d",&n) && n!=-1)
	{
		printf("%lld\n",mapa[n] );
	}
	return 0;
}

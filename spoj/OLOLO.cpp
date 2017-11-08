#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int n=0,aux=0;
	vector<int> v;
 
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&aux);
		v.push_back(aux);
	}
	sort(v.begin(),v.end());
	aux=0;
	for (int i = 0; i < v.size(); ++i)
	{
		aux^=v[i];
	}
	printf("%d\n",aux );
 
	return 0;
} 

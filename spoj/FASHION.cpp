#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int tc=0,n=0,aux=0,sum=0;
	vector<int> m;
	vector<int> f;
 
 
	scanf("%d",&tc);
	for (int i = 0; i < tc; ++i)
	{
		scanf("%d",&n);
		m.clear();
		f.clear();
		sum=0;
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&aux);
			m.push_back(aux);
		}
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&aux);
			f.push_back(aux);
		}
		sort(m.begin(), m.end());
		sort(f.begin(), f.end());
		for (int j = 0; j < n; ++j)
		{
			sum= sum + m[j]*f[j];
		}
		printf("%d\n",sum );
	}
	
	return 0;
} 

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int n=0,m=0,ini=0,f=0,cont=0,aux=0;
	vector<pair<int, int> > v;
 
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&m);
		v.clear();
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d",&ini,&f);
			v.push_back(make_pair(f,ini));                 //el par esta hecho (fin,inicio)
		}
		sort(v.begin(), v.end());
		cont=0;
		aux=0;
		for ( vector<pair<int, int> >::iterator i = v.begin(); i != v.end(); ++i)
		{
			if (i->second >= aux)
			{
				aux=i->first;
				cont++;
			}
		}
		printf("%d\n",cont );
	}
	return 0;
} 

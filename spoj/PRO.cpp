#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int t,k,aux;
	multiset<int> s;
	multiset<int>::iterator prin,fin;
	long long int ans;
 
	scanf("%d",&t);
	ans=0;
	while(t--)
	{
		scanf("%d",&k);
		for (int i = 0; i < k; ++i)
		{
			scanf("%d",&aux);
			s.insert(aux);
		}
 
		prin= s.begin();
		fin= s.end();
		fin--;
 
		ans+= (*fin) - (*prin);
 
		s.erase(prin);
		s.erase(fin);
	}
 
	printf("%lld\n",ans );
 
	return 0;
} 

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int tc=0, n=0;
	string account,aux;
	map<string, int> mp;
	map<string,int>::iterator it;
 
	scanf("%d",&tc);
	for (int i = 0; i < tc ; ++i)
	{
		mp.clear();
		scanf("%d\n",&n);
		for (int i = 0; i < n; ++i)
		{
			getline(cin,account);
			mp[account]++;
		}
		for ( it = mp.begin(); it != mp.end(); ++it)
		{
			printf("%s %d\n",(*it).first.c_str(),(*it).second );
		}
		printf("\n");
	}
 
	return 0;
} 

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int t;
	string operador;
	long long int ans, aux;
 
	scanf("%d",&t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%lld",&ans);
		while(cin>>operador && operador[0]!='=')
		{
			scanf("%lld",&aux);
			if (operador[0]=='+')
			{
				ans+= aux;
			}else if (operador[0]=='-')
			{
				ans-= aux;
			}else if (operador[0]=='*')
			{
				ans*= aux;
			}else if (operador[0]=='/')
			{
				ans/= aux;
			}
 
		}
 
		printf("%lld\n",ans );
	}
  return 0;
} 

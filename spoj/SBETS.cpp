#include <bits/stdc++.h>
#include <string>
using namespace std;
 
int main()
{
	int tc=0,eqp1=0,eqp2=0;
	char team1[4],team2[4];
	map<string,int> mapa;
	map<string,int>::iterator it,resul;
 
 
	scanf("%d",&tc);
	for (int i = 0; i < tc; ++i)
	{
		mapa.clear();
		for (int i = 0; i < 16; ++i)
		{
			scanf("%s %s %d %d",team1,team2,&eqp1,&eqp2);
			if (eqp1>eqp2)
			{
				mapa[team1]++;
			}else
			{
				mapa[team2]++;
			}
		}
		resul= mapa.begin();
		for ( it = mapa.begin(); it != mapa.end(); ++it)
		{
			if ((*it).second>(*resul).second)
			{
				resul=it;
			}
		}
 
		  cout<<(*resul).first<<endl; 
	}
 
 
	return 0;
} 

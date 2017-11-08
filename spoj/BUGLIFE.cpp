#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> grafo[2100];
int color[2100];
int cont=0;
 
bool EsBipartito(int s)
{
	queue<int> q;
	color[s]= 0;
	q.push(s);
	while(!q.empty())
	{
		int u= q.front();q.pop();
		for (vector<int>::iterator i = grafo[u].begin(); i != grafo[u].end(); ++i)
		{
			if (color[*i]==-1)
			{
				color[*i]= (color[u])?0:1;
				q.push(*i);
			}else
			{
				if (color[u]==color[*i])
				{
					return false;
				}
			}
		}
		cont++;
	}
 
	return true;
}
 
 
void ini(int x)
{
	for (int i = 0; i <= x; ++i)
	{
		grafo[i].clear();
	}
 
}
 
 
 
int main()
{
	int t,n,m,u,v,aux;
 
	scanf("%d",&t);
	aux=1;
	while(t--)
	{
		scanf("%d %d" ,&n,&m);
 
		memset(color,-1,sizeof(color));
		ini(n+1);
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d %d",&u,&v);
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}
		bool ans= true;
 
		for (int i = 1; i <=n ; ++i)
		{
			if (color[i]==-1)
			{
				ans&= EsBipartito(i);
			}
		}
 
		printf("Scenario #%d:\n", aux);
		(ans)? printf("No suspicious bugs found!\n"):printf("Suspicious bugs found!\n");
		aux++;
	}
 
	return 0;
} 

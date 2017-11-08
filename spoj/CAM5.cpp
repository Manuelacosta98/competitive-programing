#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> grafo[100010];
bool visit[100010];
 
void dfs(int u)
{
	visit[u]= true;
	for (int i = 0; i < grafo[u].size(); ++i)
	{
		int nuevo= grafo[u][i];
		if (!visit[nuevo])
		{
			dfs(nuevo);
		}
	}
}
 
 
int main()
{
	int t,n,e,a,b;
	int ans;
 
	scanf("%d",&t);
 
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&e);
 
		for (int i = 0; i < n; ++i)
		{
			visit[i]=false;
			grafo[i].clear();
		}
 
		for (int i = 0; i < e; ++i)
		{
			scanf("%d %d",&a,&b);
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		ans=0;
		for (int i = 0; i < n; ++i)
		{
			if (!visit[i])
			{
				ans++;
				dfs(i);
			}
		}
 
		printf("%d\n",ans );
	}
 
	return 0;
} 

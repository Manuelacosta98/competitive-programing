#include <bits/stdc++.h>
#define MAXSIZE 
using namespace std;
 
int grafo[300][300];
bool visit[300][300];
int n,m;
 
int movx[]= {0,1,-1,0};
int movy[]= {1,0,0,-1};
 
 
bool valido(int a, int b){
    return ((a<m && a>=0) && (b<n && b>=0))?true:false;
}
 
 
 
int dfs(int x,int y)
{
	int cont=0;
	visit[x][y]= true;
	for (int i = 0; i < 4; ++i)
	{
		int nx= x+ movx[i];
		int ny= y+ movy[i];
 
		if (valido(nx,ny) && grafo[nx][ny]==1 && !visit[nx][ny] )
		{
			cont++;
			cont+= dfs(nx,ny);
		}
	}
 
	return cont;
}
 
int main()
{
	map<int,int> mp;
	int ans;
	while(scanf("%d %d",&n,&m)!=EOF && n!=0 && m!=0)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				scanf("%d",&grafo[i][j]);
				visit[i][j]= false;
			}
		}
 
		ans=0;
		mp.clear();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (!visit[i][j] && grafo[i][j]==1)
				{
					ans++;
					mp[dfs(i,j)+1]++;
					//printf("%d\n",dfs(i,j)+1);
				}
			}
		}
 
		printf("%d\n",ans );
		for (map<int, int>::iterator i = mp.begin(); i != mp.end(); ++i)
		{
			printf("%d %d\n",(*i).first, (*i).second);
		}
	}
 
	return 0;
} 

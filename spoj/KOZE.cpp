#include <bits/stdc++.h>
 
using namespace std;
 
int movx[]={0,0,1,-1};
int movy[]={-1,1,0,0};
int n,m;
char grafo[300][300];
int visit[300][300];
int ovejas,lobos;
 
bool valido(int a, int b)
{
	return ( (a>=0 && a<n) && ( b>=0 && b<m) )? true : false;
}
 
 
void dfs(int sx,int sy)
{
	visit[sx][sy]=1;
	if (grafo[sx][sy]=='k')
	{
		ovejas++;
	}
	if (grafo[sx][sy]=='v')
	{
		lobos++;
	}
	for (int i = 0; i < 4; ++i)
	{
		int nx= sx + movx[i];
		int ny= sy + movy[i];
 
		if (valido(nx,ny) && !visit[nx][ny] && grafo[nx][ny]!='#')
		{
			dfs(nx,ny);
		}
	}
}
 
int main()
{
	scanf("%d %d",&n,&m);
	int anso=0,ansl=0;
 
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",grafo[i]);
	}
 
	memset(visit,0,sizeof(visit));
 
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!visit[i][j] && grafo[i][j]!='#')
			{
				ovejas=0; lobos=0;
				dfs(i,j);
				if (ovejas>lobos)
				{
					lobos=0;
				}else
				{
					ovejas=0;
				}
				anso+= ovejas;
				ansl+= lobos;
			}
		}	
	}
 
	printf("%d %d\n",anso,ansl);
 
	return 0;
} 

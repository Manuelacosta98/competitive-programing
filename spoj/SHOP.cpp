#include <bits/stdc++.h>
#define MAXSIZE 30
#define MAXINT 20000
using namespace std;
 
char grafo[30][30];
int dist[30][30];
int movx[]= {0,1,-1,0};
int movy[]= {1,0,0,-1};
int n,m;
 
 
bool valida(int a, int b){
    return ((a<m && a>=0) && (b<n && b>=0))?true:false;
}
 
 
void bfs(int sx, int sy)
{
	queue< pair<int,int> > q;
	dist[sx][sy]=0;
	q.push(make_pair(sx,sy));
 
	while(!q.empty())
	{
		pair<int,int> u= q.front(); q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx= u.first + movx[i];
			int ny= u.second + movy[i];
			if (valida(nx,ny) && isdigit(grafo[nx][ny]) && dist[u.first][u.second] + (grafo[nx][ny] -'0')< dist[nx][ny] )
			{
				dist[nx][ny]= dist[u.first][u.second] + (grafo[nx][ny]-'0');
				q.push( make_pair(nx,ny) );
			}
		}
 
	}
}
 
 
 
 
void inicializar(int x, int visit[][MAXSIZE])
{
	for (int i = 0; i < MAXSIZE; ++i)
	{
		for (int j = 0; j < MAXSIZE; ++j)
		{
			visit[i][j]=x;
		}
	}
}
 
 
int main()
{
 
	while(scanf("%d %d",&n,&m)!=EOF && n!=0 && m!=0)
	{
		for (int i = 0; i < m; ++i)
		{
			scanf("%s",grafo[i]);
		}
 
		pair<int,int> S,D;
		inicializar(MAXINT,dist);
 
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grafo[i][j]=='S')
				{
					S= make_pair(i,j);
					grafo[i][j]='0';
				}
 
				if (grafo[i][j]=='D')
				{
					D= make_pair(i,j);
					grafo[i][j]='0';
				}
			}
		}
 
		bfs(S.first,S.second);
		printf("%d\n",dist[D.first][D.second]);
	}
	
	return 0;
} 

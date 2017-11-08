#include <bits/stdc++.h>
#define X first
#define Y second
#define MAXINT 20000000
 
using namespace std;
 
 
int movx[]={0,0,-1,1};
int movy[]={1,-1,0,0};
 
 
int grafo[150][150];
int dist[150][150];
int t,n,m,auxn,auxm,tiempo;
 
bool valido(int a, int b)
{
	if ( (a>0 && a<=n) && b>0 && b<=m)
	{
		return true;
	}else
	{
		return false;
	}
}
 
void bfs(int sx,int sy)
{
	queue<pair<int,int> > q;
	pair<int,int> u;
	dist[sx][sy]= grafo[sx][sy];
	q.push( make_pair(sx,sy) );
 
	while(!q.empty())
	{
		u= q.front(); q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx= u.X + movx[i];
			int ny= u.Y + movy[i];
			if (valido(nx,ny) && dist[u.X][u.Y]+ grafo[nx][ny] < dist[nx][ny])
			{
				dist[nx][ny]= dist[u.X][u.Y]+ grafo[nx][ny];
				q.push( make_pair(nx,ny) );
			}
		}
	}
}
 
 
void inicializar(int array[][150],int n,int m,int x)
{
	for (int i = 0; i <=n  ; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			array[i][j]=x;
		}
	}
}
 
 
int main()
{
	pair<int,int> D;
	int aux;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		memset(grafo,0,sizeof(grafo));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				scanf("%d",&grafo[i][j]);
			}
		}
 
		scanf("%d %d %d",&auxn,&auxm,&tiempo);
		D= make_pair(auxn,auxm);
		inicializar(dist,n,m,MAXINT);
		bfs(1,1);
 
		aux= tiempo - dist[D.X][D.Y];
 
		if (aux<0)
		{
			printf("NO\n");
		}else
		{
			printf("YES\n");
			printf("%d\n",aux );
		}
	}
	
	return 0;
} 

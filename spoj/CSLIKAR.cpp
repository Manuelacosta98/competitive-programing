#include <bits/stdc++.h>
#define X first
#define Y second
#define MAXINT 2000000
 
 
using namespace std;
 
int movx[]= {1,0,-1,0};
int movy[]= {0,1,0,-1};
 
char grafo[60][60];
int dist[60][60];
int dist2[60][60];
int n=0, m=0;
 
bool valida(int a, int b){
    return ((a<n && a>=0) && (b<m && b>=0))?true:false;
}
 
 
void FloodFill(int sx,int sy)
{
	dist[sx][sy]=0;
	queue<pair<int,int> >q;
	pair<int, int> u;
	q.push( make_pair(sx,sy) );
 
	while(!q.empty())
	{
		u= q.front(); q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx= u.X + movx[i];
			int ny= u.Y + movy[i];
			if (valida(nx,ny) && (grafo[nx][ny]!='X' && grafo[nx][ny]!='S' && grafo[nx][ny]!='D') && dist[u.X][u.Y] +1 < dist[nx][ny])
			{
				dist[nx][ny]= dist[u.X][u.Y] +1;
				q.push( make_pair(nx,ny) );
			}
		}
	}
}
 
void bfs(int sx, int sy)
{
	dist2[sx][sy]=0;
	queue<pair<int,int> >q;
	pair<int, int> u;
	q.push( make_pair(sx,sy) );
 
	while(!q.empty())
	{
		u= q.front(); q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx= u.X + movx[i];
			int ny= u.Y + movy[i];
			if (valida(nx,ny) && grafo[nx][ny]!='X' && dist2[u.X][u.Y] +1 < dist2[nx][ny])
			{
				if (dist2[u.X][u.Y] +1 < dist[nx][ny])
				{
					dist2[nx][ny]= dist2[u.X][u.Y] +1;
					q.push( make_pair(nx,ny) );
				}
			}
		}
	}
}
 
void inicializar(int x)
{
	for (int i = 0; i < 60; ++i)
	{
		for (int j = 0; j < 60; ++j)
		{
			dist[i][j]=x;
		}
	}
}
 
int main()
{
	vector< pair<int,int> > v;
	scanf("%d %d",&n,&m);
 
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",grafo[i]);
	}
 
	pair<int, int> ini, fin;
 
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (grafo[i][j]=='S')
			{
				ini= make_pair(i,j);
			}
 
			if (grafo[i][j]=='D')
			{
				fin= make_pair(i,j);
			}
 
			if (grafo[i][j]=='*')
			{
				v.push_back( make_pair(i,j) );
			}
		}
	}
	inicializar(MAXINT);
	//cout<<"n.Lagunas= "<<v.size()<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		FloodFill(v[i].X,v[i].Y);
	}
 
	for (int i = 0; i < 60; ++i)
	{
		for (int j = 0; j < 60; ++j)
		{
			dist2[i][j]=MAXINT;
		}
	}
 
	/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%d ", dist[i][j] );
		}
		printf("\n");
	}
	*/
 
	bfs(ini.X,ini.Y);
	(dist2[fin.X][fin.Y]!=MAXINT)?printf("%d\n",dist2[fin.X][fin.Y]):printf("KAKTUS\n");;
 
 
/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%d ", dist2[i][j] );
		}
		printf("\n");
	}
*/
	return 0;
 
} 

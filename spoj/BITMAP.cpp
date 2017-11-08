#include <bits/stdc++.h>
#define MAXSIZE 200
#define MAXINT 20000000
using namespace std;
 
char grafo[200][200];
int visit[MAXSIZE][MAXSIZE];
int movx[]= {0,1,-1,0};
int movy[]= {1,0,0,-1};
int t,n,m,aux;
 
bool valida(int a, int b){
    return ((a<n && a>=0) && (b<m && b>=0))?true:false;
}
 
 
 
void bfs(int x, int y)
{
	queue< pair<int,int> >q;
	visit[x][y]=0;
	q.push(make_pair(x,y));
 
	while(!q.empty())
	{
		pair<int,int> u= q.front(); q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nuevox= u.first+movx[i];
			int nuevoy= u.second+movy[i];
			if ( valida(nuevox,nuevoy) && visit[u.first][u.second] + 1 < visit[nuevox][nuevoy])
			{
				visit[nuevox][nuevoy]= visit[u.first][u.second] + 1;
				q.push(make_pair(nuevox, nuevoy) );
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
	string cadena;
 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		inicializar(MAXINT,visit);
 
		for (int i = 0; i < n; ++i)
		{
			scanf("%s",grafo[i]);
		}
 
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grafo[i][j]=='1')
				{
					bfs(i,j);
				}
			}
		}
 
 
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
 
				printf("%d",visit[i][j] );
				if (j!=m-1)
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
 
	return 0;
} 

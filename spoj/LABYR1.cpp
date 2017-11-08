#include <bits/stdc++.h>
#define MAXINT 20000000
#define MAXSIZE 1100
 
using namespace std;
int t,n,m;
char grafo[1100][1100];
int dist[1100][1100];
 
int movx[]= {0,1,-1,0};
int movy[]= {1,0,0,-1};
 
bool valida(int a, int b){
    return ((a<m && a>=0) && (b<n && b>=0))?true:false;
}
 
pair<int,int> bfs(int sx,int sy)
{
	queue< pair<int,int> >q;
 
	pair<int,int> maxi;
	dist[sx][sy]=0;
	q.push(make_pair(sx,sy));
 
	while(!q.empty())
	{
		pair<int, int> u= q.front(); q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nuevoX= u.first+ movx[i];
			int nuevoy= u.second+ movy[i];
			if (valida(nuevoX,nuevoy) && grafo[nuevoX][nuevoy]=='.' && dist[u.first][u.second] + 1 < dist[nuevoX][nuevoy])
			{
				dist[nuevoX][nuevoy]= dist[u.first][u.second] + 1;
				maxi= make_pair(nuevoX,nuevoy);
				q.push(maxi);
			}
		}
 
	}
 
	return maxi;
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
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for (int i = 0; i < m; ++i)
		{
			scanf("%s",grafo[i]);
		}
 
		bool algo= false;
		pair<int,int> a;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grafo[i][j]=='.')
				{
					a= make_pair(i,j);
					algo= true;
					break;
				}
			}
			if (algo)
			{
				break;
			}
		}
		inicializar(MAXINT,dist);
		pair<int,int> aux= bfs(a.first,a.second);
		inicializar(MAXINT,dist);
		pair<int,int> aux2= bfs(aux.first,aux.second);
 
		int res= 0;
		res= dist[aux2.first][aux2.second];
 
		printf("Maximum rope length is %d.\n",res );
	}
 
 
	return 0;
} 

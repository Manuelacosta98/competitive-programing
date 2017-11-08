#include <bits/stdc++.h>
#define X first
#define Y second
 
using namespace std;
 
int n,k,x,y;
 
char grafo[550][550];
int dist[550][550];
 
vector< pair<int,int> > v;
int movx[]= {0,1,-1,0,1,1,-1,-1};
int movy[]= {1,0,0,-1,1,-1,1,-1};
 
bool valido(int a, int b){
    return ((n>=a && a>0) && (n>=b && b>0))?true:false;
}
 
void bfs(int sx,int sy)
{
	queue< pair<int,int> > q;
	dist[sx][sy]= 5;
 
	q.push( make_pair(sx,sy) );
 
	while(!q.empty())
	{
		pair<int,int> u= q.front(); q.pop();
		for (int i = 0; i < 8; ++i)
		{
			int nx= u.X + movx[i];
			int ny= u.Y + movy[i];
			if (valido(nx,ny) && dist[u.X][u.Y] -1 > dist[nx][ny])
			{
				dist[nx][ny]= dist[u.X][u.Y] -1;
				q.push( make_pair(nx,ny) );
			}
		}
	}
}
 
 
int main()
{
	scanf("%d %d",&n,&k);
 
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <n ; ++j)
		{
			cin>>grafo[i][j];
		}
	}
 
	for (int i = 1; i <= n+1; ++i)
	{
		for (int j = 1; j <= n+1; ++j)
		{
			dist[i][j]=1;
		}
	}
 
	for (int i = 0; i < k; ++i)
	{
		scanf("%d %d",&x,&y);
		bfs(x,y);
	}
 
	/*for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			printf("%d ",dist[i][j]);
		}
		printf("\n");
	}*/
 
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			printf("%c", ((char)((((int)grafo[i-1][j-1])*dist[i][j]) %93) + 33) );
			if (j!=n)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
 
	return 0;
} 

#include <bits/stdc++.h>
#define MAXSIZE 1010
#define INFINITO 0x3f3f3f3f
using namespace std;
 
 
class Edge
{
public:
	int X;
	int Y;
	int peso;
	Edge();
	Edge(int a,int b,int w)
	{
		X=a;
		Y=b;
		peso=w;
	}
 
	bool operator<(const Edge &otro)const{
		return (peso>otro.peso)?true:false;
	}
	
};
 
 
int t,n,m,k;
 
char grafo[MAXSIZE][MAXSIZE];
int dist[MAXSIZE][MAXSIZE];
 
int movx[]= {0,1,-1,0};
int movy[]= {1,0,0,-1};
 
bool valido(int a, int b){
    return ((a<n && a>=0) && (b<m && b>=0))?true:false;
}
 
void bfs(int sx,int sy)
{
	priority_queue<Edge>q;
	int nx,ny;
	dist[sx][sy]=0;
	q.push( Edge(sx,sy,0) );
 
	while(!q.empty())
	{
		Edge u= q.top();q.pop();
 
		for (int i = 0; i < 4; ++i)
		{
			nx= u.X + movx[i];
			ny= u.Y + movy[i];
 
			if (valido(nx,ny) && dist[u.X][u.Y] + 1 + (grafo[u.X][u.Y]-'0') < dist[nx][ny] )
			{
				dist[nx][ny]= dist[u.X][u.Y] + 1 + (grafo[u.X][u.Y]-'0');
				q.push( Edge(nx,ny,dist[nx][ny]) );
			}
		}
	}
}
 
 
int main()
{
	pair<int,int> D,I;
	scanf("%d",&t);
	for (int tt = 1; tt <=t ; ++tt)
	{
		scanf("%d %d %d",&n,&m,&k);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s",grafo[i]);
		}
 
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grafo[i][j]=='R')
				{
					I= make_pair(i,j);
					grafo[i][j]='0';
				}else if (grafo[i][j]=='D')
				{
					D= make_pair(i,j);
					grafo[i][j]='0';
				}else
				{
					if (grafo[i][j]=='.')
					{
						grafo[i][j]='0';
					}
				}
				dist[i][j]= INFINITO;
			}
		}
/*
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				printf("%c",grafo[i][j] );
			}
			printf("\n");
		}
		*/
 
		bfs(I.first,I.second);
		int ans= dist[D.first][D.second];
		(ans<k)?printf("Scenario #%d: %d\n",tt, ans):printf("Scenario #%d: Ronny will be destroyed\n",tt );
	}
	
	return 0;
} 

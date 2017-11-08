#include <bits/stdc++.h>
#define X first
#define Y second
 
using namespace std;
 
int MovX[]= {2,-2,1,-1,2,-2,1,-1};
int MovY[]= {1,1,2,2,-1,-1,-2,-2};
 
int grafo[8][8];
int dist[8][8];
bool visit[8][8];
 
bool esValido(int x, int y)
{
	return (x>0 && x<=8 && y>0 && y<=8)? true: false;
}
 
 
void bfs(int sx, int sy)
{
	queue< pair<int,int> > q;
	dist[sx][sy]=0;
	q.push( make_pair(sx,sy) );
	visit[sx][sy]= true;
	while(!q.empty())
	{
		pair<int,int> u= q.front(); q.pop();
		for (int i = 0; i < 8; ++i)
		{
			int nuevoX= u.X+ MovX[i];
			int nuevoY= u.Y + MovY[i];
			if (esValido(nuevoX,nuevoY) && !visit[nuevoX][nuevoY] && dist[u.X][u.Y] + 1 < dist[nuevoX][nuevoY])
			{
				visit[u.X][u.Y]= true;
				dist[nuevoX][nuevoY]= dist[u.X][u.Y]+ 1;
				q.push( make_pair(nuevoX, nuevoY) );
			}
		}
	}
}
 
 
int main()
{
	int t;
	char a[3], b[3];
	map<char,int> m;
 
	m['a']=m['1']=1;
	m['b']=m['2']=2;
	m['c']=m['3']=3;
	m['d']=m['4']=4;
	m['e']=m['5']=5;
	m['f']=m['6']=6;
	m['g']=m['7']=7;
	m['h']=m['8']=8;
 
	scanf("%d",&t);
	while(t--)
	{
		for (int i = 1; i <= 8; ++i)
		{
			for (int j = 1; j <= 8; ++j)
			{
				dist[i][j]=2000000;
				visit[i][j]= 0;
			}
		}
		scanf("%s %s",a,b);
		bfs(m[a[0]],m[a[1]]);
		printf("%d\n", dist[ m[b[0]] ][ m[b[1]]]);
		//printf("desde %d %d\n", m[a[0]],m[a[1]]);
 
		//printf("hasta %d %d es %d \n", m[b[0]],m[b[1]], dist[ m[b[0]] ][ m[b[1]]] );
		/*
		for (int i = 1; i <= 8; ++i)
		{
			for (int j = 1; j <= 8; ++j)
			{
				printf("%d ",dist[i][j]);
			}
			printf("\n");
		}
		*/
	}
 
	return 0;
} 

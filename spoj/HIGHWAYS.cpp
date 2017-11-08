#include <bits//stdc++.h>
#define nodo second
#define peso first
#define MAXINT 2000000
 
using namespace std;
 
vector< pair<int,int> > grafo[100100];
int dist[100100];
 
int t,n,m,a,b,p,ini,fin;
 
void inicializarD(int x,int n)
{
	for (int i = 0; i <= n; ++i)
	{
		dist[i]= x;
	}
}
 
 
void Dijkstra(int source, int destiny)
{
	inicializarD(MAXINT,n+10);
	dist[source]=0;
	priority_queue< pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q;
	int v;
	int peso_u_v;
 
	q.push( make_pair(0,source) );
 
	while(!q.empty())
	{
		pair<int,int> u= q.top(); q.pop();
 
		for (int i = 0; i < grafo[u.nodo].size(); ++i)
		{
			peso_u_v= grafo[u.nodo][i].peso;
			v= grafo[u.nodo][i].nodo;
 
			if (dist[u.nodo] + peso_u_v < dist[v])
			{
				dist[v]= dist[u.nodo] + peso_u_v;
				q.push( make_pair(peso_u_v,v) );
			}
		}
	}
 
	(dist[fin]==MAXINT)?printf("NONE\n"):printf("%d\n",dist[fin] );
 
}
 
void inicializarG(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		grafo[i].clear();		
	}
}
 
int main()
{
 
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d %d %d %d",&n,&m,&ini,&fin);
		inicializarG(n);		
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d %d",&a,&b,&p);
			grafo[a].push_back( make_pair(p,b) );
			grafo[b].push_back( make_pair(p,a) );
		}
 
		Dijkstra(ini,fin);
 
		t--;
	}
	return 0;
} 

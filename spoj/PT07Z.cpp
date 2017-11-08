#include <bits/stdc++.h>
 
using namespace std;
 
vector< int > ady[10010];
int dist[10010];
 
 
int max(int x, int y)
{
	return (x>y)?x:y;
}
 
int bfs(int s, int size){
	int maxi=0;
	int v;
	int aux;
	queue<int> q;
 
	memset(dist, -1, sizeof(dist));
	dist[s] = 0;
	q.push(s);
 
	while (!q.empty()) {
		int u = q.front(); q.pop(); 
 
		for (int i=0; i<ady[u].size();++i)
		{
 
			v = ady[u][i];
			if (dist[v]==-1) { 
				q.push(v);
				dist[v] = dist[u] + 1;
				aux= v;
			}
		}
	}
 
	return aux;
}
 
 
int main()
{
 
	int n=0,m=0,u=0,v=0;
 
	scanf("%d",&n);
 
	for (int i = 0; i < n-1; ++i)
	{
		scanf("%d %d",&u,&v);
		ady[u-1].push_back(v-1);
		ady[v-1].push_back(u-1);	
	}
 
	int aux=bfs(0, n);
	int sol= bfs(aux, n);
	sol= dist[sol];
 
	printf("%d\n",sol );
 
 
	return 0;
} 

#include <bits//stdc++.h>
#define SIZE 10100
#define DFS_WHITE -1
using namespace std;

int dfs_low[SIZE], dfs_num[SIZE],dfs_parent[SIZE],articulation_vertex[SIZE], dfsNumberCounter, rootChildren, dfsRoot, V ;

vector<int> grafo[SIZE];


int min(int a,int b)
{
  return (a<b)?a:b;
}


void inicializarG(int n)
{
  for (int i = 0; i <= n; ++i)
  {
    grafo[i].clear();		
  }
}


void articulationPointAndBridge(int u) 
{
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
  for (int i = 0; i < grafo[u].size(); ++i)
  {
    int v= grafo[u][i];
    if (dfs_num[v] == DFS_WHITE) { // a tree edge
      dfs_parent[v] = u; // parent of this children is me
      if (u == dfsRoot) // special case
        rootChildren++; // count children of root
      articulationPointAndBridge(v);
      if (dfs_low[v] >= dfs_num[u]) // for articulation point
        articulation_vertex[u] = true; // store this information first
      //if (dfs_low[v] > dfs_num[u]) // for bridge
        //printf(" Edge (%d, %d) is a bridge\n", u, v);
      dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
    }
    else if (v != dfs_parent[u]) // a back edge and not direct cycle
      dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
  }
}

int main()
{
  int E,a,b;
  while(scanf("%d %d",&V,&E) && (V!=0 && E!=0) )
  {
    inicializarG(V);
    for (int i = 0; i < E; ++i)
    {
      scanf("%d %d", &a,&b);
      grafo[a].push_back(b);
      grafo[b].push_back(a);
    }


    dfsNumberCounter = 0;
    memset(dfs_num, DFS_WHITE, sizeof dfs_num);
    memset(articulation_vertex, false, sizeof articulation_vertex);
    //printf("Bridges:\n");
    dfsRoot = 1; rootChildren = 0;
    articulationPointAndBridge(1);
    articulation_vertex[dfsRoot] = (rootChildren > 1); // special case
    /*for (int i = 1; i <= V; ++i)
    {
      if (dfs_num[i] == DFS_WHITE) {
        dfsRoot = i; rootChildren = 0;
        articulationPointAndBridge(i);
        articulation_vertex[dfsRoot] = (rootChildren > 1); // special case
      }
    }*/
    int ans=0;	
    //printf("Articulation Points:\n");
    for (int i = 1; i <= V; ++i)
    {
      if (articulation_vertex[i])
      {
        ans++;
        //printf(" Vertex %d\n", i);
      }
    }

    printf("%d\n",ans );

  }

  return 0;
}  

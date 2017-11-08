#include <bits/stdc++.h>
using namespace std;
 
class UF {
  int *id, cnt, *sz;
  public:
// Create an empty union find data structure with N isolated sets.
UF(int N) {
    cnt = N; id = new int[N]; sz = new int[N];
    for (int i = 0; i<N; i++)  id[i] = i, sz[i] = 1; }
~UF() { delete[] id; delete[] sz; }
 
// Return the id of component corresponding to object p.
int find(int p) {
    int root = p;
    while (root != id[root])    root = id[root];
    while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
    return root;
}
// Replace sets containing x and y with their union.
void merge(int x, int y) {
    int i = find(x); int j = find(y); if (i == j) return;
    // make smaller root point to larger one
    if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
    else { id[j] = i, sz[i] += sz[j]; }
    cnt--;
}
// Are objects x and y in the same set?
bool connected(int x, int y) { return find(x) == find(y); }
// Return the number of disjoint sets.
int count() { return cnt; }
};
 
 
int main() {
	int n=0,m=0,u=0,v=0;
 
	scanf("%d %d",&n, &m);
	UF *set= new UF(n+1);
 
	if (m != n-1)
	{
		printf("NO\n");
		return 0;
	}
 
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d",&u,&v);
		if ( !set->connected(u,v))
		{
			set->merge(u,v);
		}else
		{
			printf("NO\n");
			return 0;		
		}
		
	}
	
	printf("YES\n");
	
	return 0;
} 

#include <bits/stdc++.h>
 
using namespace std;
 
int n,aux;
char matriz[11][11];
int Memo[11][11];
 
bool valido(int x,int y)
{
	return (x>=0 && x<n && y>=0 && y<n)? true: false;
}
 
 
 
int DP(int x,int y)
{
	int pasos= matriz[x][y]-'0';
	if (x==n-1 && y==n-1) return 1;
	if(!valido(x,y) || pasos==0) return 0;
	if (Memo[x][y]!=-1) return Memo[x][y];
 
	int &mejor = Memo[x][y];
 
	mejor= DP(x+(pasos),y ) + DP(x, y+(pasos)) ;
 
	return mejor;
}
 
int main()
{
 
	memset(Memo,-1,sizeof(Memo));
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",matriz[i]);
	}
 
	printf("%d", (DP(0,0)<=200000)?DP(0,0):0 );
 
	return 0;
} 

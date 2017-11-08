#include <iostream>
#include <string>
using namespace std;
const int N=2005;
int a[N][N];
void makezero(int x, int y)
{
	for(int i=0;i<=x;i++)
		for(int j=0;j<=y;j++)
			a[i][j]=0;
}
int min(int x,int y, int z)
{
	if(x<=y && x<=z)
		return x;
	if(y<=x && y<=z)
		return y;	
	return z;
}
 
int main() 
{
	string s1,s2;
	int t,k,n,m,i,j,b,c,d;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		cin>>s1>>s2;
		n=s1.size();
		m=s2.size();
		makezero(n,m);
		for(i=0;i<=n;i++)
			a[i][0]=i;
		for(i=0;i<=m;i++)
			a[0][i]=i;
		s1='_'+s1;
		s2='_'+s2;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				if(s1[i]==s2[j])
					a[i][j]=min(a[i-1][j]+1,a[i][j-1]+1,a[i-1][j-1]);
				else
					a[i][j]=min(a[i-1][j]+1,a[i][j-1]+1,a[i-1][j-1]+1);
					
			}
		cout<<a[n][m]<<endl;
			
	}
	
	
	// your code goes here
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
 
 
int reverse(int x)
{
	int result=0;
	while(x>0)
	{
		result= result * 10;
		result= result + (x%10);
		x= x/10;
	}
	return result;
}
 
 
int main()
{
int n=0,x=0,y=0;
scanf("%d",&n);
 
for(int i=0;i<n;i++)
{
	scanf("%d %d",&x,&y);
	printf("%d\n",reverse(reverse(x)+reverse(y)));
}
 
    return 0;
} 

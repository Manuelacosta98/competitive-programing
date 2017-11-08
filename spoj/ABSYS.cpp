#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
 
#define MOD 1000000007LL
#define LL long long
#define ULL unsigned long long
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x)   ((x)<0?-(x):(x))
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")//print new line
#define REP(n) for(int i=0;i<(n);i++)//repeat n times
#define FOR(a,b) for(int i=(a);i<(b);i++)//end not included
#define FORR(n) for(int i=(n);i>=0;i--)//reverse for
 
using namespace std;
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)
    {
        char c;
        int f1=0,f2=0,f3=0;
        int n1=0,n2=0,n3=0;
        int p=0;
        scanf("\n%c",&c);
        while(c!='\n')
        {
            if(p==0)
            {
                if(c>=48 && c<=57)
                {
                    n1=n1*10 + (c-48);
                }
                else
                {
                    p++;
                    if(c=='m')
                        f1=1;
                    while(c!='+')
                        scanf("%c",&c);
                    scanf("%c",&c);
                }
            }
            else if(p==1)
            {
                if(c>=48 && c<=57)
                {
                    n2=n2*10 + (c-48);
                }
                else
                {
                    p++;
                    if(c=='m')
                        f2=1;
                    while(c!='=')
                        scanf("%c",&c);
                    scanf("%c",&c);
                }
            }
            else if(p==2)
            {
                if(c>=48 && c<=57)
                {
                    n3=n3*10 + (c-48);
                }
                else
                {
                    p++;
                    if(c=='m')
                        f3=1;
                }
            }
            scanf("%c",&c);
        }
        if(f1==1)
        {
            printf("%d + %d = %d\n",(n3-n2),n2,n3);
        }
        else if(f2==1)
        {
            printf("%d + %d = %d\n",n1,(n3-n1),n3);
        }
        else if(f3==1)
        {
            printf("%d + %d = %d\n",n1,n2,(n1+n2));
        }
    }
	return 0;
} 

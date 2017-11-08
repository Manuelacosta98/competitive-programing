#include <bits/stdc++.h>
using namespace std;
 
int main() {
   
   int t,n;
   long long trabajo=0;
 
   while(scanf("%d",&n)!=EOF && n!=0)
   {
     trabajo=0;
      int arr[n];
      for(int i=0 ; i<n ; ++i)
         scanf("%d",&arr[i]);
      for(int i=1 ; i<n ; ++i)	
      {
         arr[i] += arr[i-1];
         trabajo += abs(arr[i-1]);
      }
      printf("%lld\n",trabajo );
   }
   return 0;
} 

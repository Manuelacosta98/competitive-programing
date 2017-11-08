#include <bits/stdc++.h>
#define SIZE 1100
using namespace std;


int primes[100000];
vector<int> p;

void sieve(int top)
{
  memset(primes, false, sizeof(primes));
  for (int i = 2; i*i <= top ; ++i)
  {
    if (primes[i]==0)
    {
      for (int j = i*2; j <= top; j+=i)
      {
        primes[j]= primes[j]+1;
      }
    }


  }

  for (int i = 2; i <= top; ++i)
  {
    if (primes[i]==0)
    {
      p.push_back(i);
    }
  }
}

vector<int> ans;
void LuckyNumber()
{
  for (int i = 0; i <= 3000; ++i)
  {
    int cont=0;
    for (int j = 0; j <p.size() && i>=p[j] ; ++j)
    {
      if (i%p[j]==0)
      {
        cont++;
      }
    }

    if (cont>=3)
    {
      ans.push_back(i);
    }
  }
}



int main()
{
  int t,n;
  //printf("1\n");
  sieve(10000);
  //printf("numero de numeros suertudos %d\n",(int) p.size() );
  /*
  for (vector<int>::iterator i = LuckyN.begin(); i != LuckyN.end(); ++i)
  {
    printf("%d, ",*i );
  }
  */
  LuckyNumber();



  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    printf("%d\n",ans[n-1] );
  }
  return 0;
}  

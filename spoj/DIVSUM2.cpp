#include <bits/stdc++.h>
#define MAX 100000107
#define MOD 10000000000000000

using namespace std;


std::vector<unsigned long long> prime;
bool p[MAX+1];

typedef unsigned long long llu;

llu mulmod(llu a, llu b, llu mod)
{
  llu res = 0; // Initialize result
  a = a % mod;
  while (b > 0)
  {
      // If b is odd, add 'a' to result
      if (b % 2 == 1)
          res = (res + a) % mod;

      // Multiply 'a' with 2
      a = (a * 2) % mod;

      // Divide b by 2
      b /= 2;
  }

  // Return result
  return res % mod;
}

void sieve(int max)
{
  memset(p,true,sizeof(p));
  for (int i = 2; i*i <= max ; ++i)
  {
    if (p[i])
    {
      for (int j = i*2;  j <=max ; j+=i)
      {
        p[j]= false;
      }
    }
  }

  for (int i = 2; i <=max ; ++i)
  {
    if (p[i])
    {
      prime.push_back(i);
    }
  }
  }

  vector< pair<llu ,int> > factores;
  void factorizacion(llu num)
  {
  int exp=0;
  int primo=0;
  factores.clear();
  for (int i = 0; prime[i]*prime[i]<= num; ++i)
  {
    exp=0;
    primo= prime[i]; 
    while (num%primo==0)
    {
      exp++;
      num/= primo;
    }

    if (exp>0)
    {
      factores.push_back( make_pair(primo,exp));
    }

}

if (num>=2)
{
  factores.push_back( make_pair(num,1) );
}
}


vector <llu> divisors;

void setDivisors(llu  cur,int i){
  if(i==factores.size()){
      //cur aqui es un divisor
      divisors.push_back(cur);
      return;
  }
  for(int j=0;j<=factores[i].second;j++){
      setDivisors(cur,i+1);


      cur= mulmod(factores[i].first,cur,MOD);
  }
}



int main()
{
int t=0;
llu sum=0, n;
sieve(MAX);

scanf("%d",&t);



while(t--)
{
  scanf("%lld", &n);
  sum=0;
  factorizacion(n);
  divisors.clear();
  setDivisors(1,0);
/*
  cout<<"primos: ";
  for (int i=0; prime[i]<n; ++i)
  {
    cout<<prime[i]<<" ";
  }
  cout<<"\n";

  cout<<"factores: ";
  for (int i=0; i<factores.size(); ++i)
  {
    cout<<factores[i].first<<" ";
  }
  cout<<"\n";

  sort(divisors.begin(), divisors.end());
      cout <<"divisores "<<divisors.size() << "\n";
      for (int j = 0; j < divisors.size(); j++) {
          cout << divisors[j] << " "; 
      }
      cout << "\n";
*/
  for (vector<llu>::iterator i = divisors.begin(); i != divisors.end(); ++i)
  {
    sum+=(*i<n)?*i:0;
  }

  printf("%llu\n",sum );

}


return 0;
}  

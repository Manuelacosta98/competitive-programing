#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
 
int n;
 
cin >>n;
int cont=0;
for (int i=1; i*i<=n;i++){
	for (int j=i; j*i<=n; j++)
		cont++;
 
 
 
}
 
cout <<cont<<"\n";
 
 
 
 
 
return 0;
 
} 

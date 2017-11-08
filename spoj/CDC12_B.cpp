#include <bits/stdc++.h>
 
using namespace std;
 
class Rutina
{
public:
	string nombre;
	int energia;
 
	Rutina(){};
	Rutina(string cadena, int valor)
	{
		nombre= cadena;
		energia= valor;
	}
	
	bool operator< (const Rutina &otro)const
	{
		if (energia==otro.energia)
		{
			return nombre< otro.nombre;
		}else
		{
			return energia<otro.energia;
		}
	}
};
 
vector<Rutina> rutinas;
 
int main()
{
	int t, n,k;
	string nombre;
	int valor;
	vector<string> ans;
 
	scanf("%d",&t);
 
 
	for (int tt = 1; tt <= t; ++tt)
	{
		ans.clear();
		rutinas.clear();
		scanf("%d %d",&n,&k);
		for (int i = 0; i < n; ++i)
		{
			cin>>nombre>>valor;
			rutinas.push_back( Rutina(nombre,valor) );
		}
 
		sort(rutinas.begin(),rutinas.end());
 
		int aux=0;
		for (int i = 0; i < n; ++i)
		{
			k-= rutinas[i].energia;
			if (k<0)
			{
				break;
			}
			aux++;
			ans.push_back(rutinas[i].nombre);
			k+=aux;
		}
 
		sort(ans.begin(),ans.end());
		printf("Scenario #%d: %d\n",tt,(int)ans.size());
		
 
		for (int i = 0; i < ans.size()-1; ++i)
		{
			printf("%s ",ans[i].c_str());
		}
 
		printf("%s\n",ans.back().c_str());
	}
 
	return 0;
}

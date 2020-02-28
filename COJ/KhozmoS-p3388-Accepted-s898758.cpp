#include <bits/stdc++.h>

using namespace std;
string numb;
int rest;
string resta (string cad2)
{
    string sol = "";
    string cad = cad2;
    sort(cad2.begin(),cad2.end());
    int ta = cad.size();
    if(cad == cad2)
     return "0";

    for(int i = ta - 1 ; i >= 0 ; i--)
    {
         int nma = cad[i] - '0';
            nma -= rest;
            rest = 0;
         int nmm = cad2[i] - '0';
         if(nma < nmm){
            nma += 10;
            rest++;
                     }
         int num = nma - nmm;
         sol = (char(num + 48)) + sol;

    }
    int i = 0;
    string sol1;
    int cont0 = 0;
     while(sol[i] == '0')
     {
        cont0++;
        i++;
     }
    for(int i = cont0 ; i < sol.size(); i++)
        sol1 += sol[i];
     return sol1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int cont = 0;
    string cad;
    cin>>cad;
     while(cad != "0")
     {
     cad = resta(cad);
     cont++;
     }
     cout<<cont<<"\n";
    return 0;
}

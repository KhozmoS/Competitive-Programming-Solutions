//KMP by KhozmoS

#include <bits/stdc++.h>
//int comp = val[cad[0]] - (pow(val[cad[1]] , 2)) + (pow(val[cad[2]] , 3)) - (pow(val[cad[3]] , 4)) + (pow(val[cad[4]] , 5));
//v - w^2 + x^3 - y^4 + z^5 = target
using namespace std;
int target;
string alpha;
char val[200];
bool flag = false;

void crear()
{
    for(int i = 0 ; i < 26 ; i++)
     val[char('A' + i)] = i + 1;
}
int ta;
bool m[200];
stack <string> pila;

void F(string cad , bool *mk)
{
   if(cad.size() == 5)
   {
     int comp = val[cad[0]] - (pow(val[cad[1]] , 2)) + (pow(val[cad[2]] , 3)) - (pow(val[cad[3]] , 4)) + (pow(val[cad[4]] , 5));

     if(comp == target)
     {
      pila.push(cad);
      flag = true;
      return;
     }
     return;
   }

  for(int i = 0 ; i < ta ; i++)
  {
    if(!mk[alpha[i]])
    {
     mk[alpha[i]] = true;
     F(cad + alpha[i] , mk);
     mk[alpha[i]] = false;
    }

  }
}

int main()
{

   crear();

    while(cin>>target>>alpha)
    {
        if(!target && alpha == "END")
        return 0;

        ta = alpha.size();
        sort(alpha.begin() , alpha.end());

        F("" , m);
        if(flag) cout<<pila.top()<<"\n";

        if(!flag) cout<<"no solution\n";

        while(!pila.empty())
            pila.pop();

        flag = false;
    }

    return 0;
}

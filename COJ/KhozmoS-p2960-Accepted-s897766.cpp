#include <bits/stdc++.h>

using namespace std;

int main()
{
    string cad;
    cin>>cad;
    int cont=0;
    for(int i = 0;i<cad.size();i++)
    {
      if(cad[i]=='A'||cad[i]=='D'||cad[i]=='O'||cad[i]=='P'||cad[i]=='Q'||cad[i]=='R')
        cont++;
      else if(cad[i]=='B')
        cont+=2;
    }
cout<<cont<<endl;

    return 0;
}


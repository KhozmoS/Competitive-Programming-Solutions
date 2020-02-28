#include<bits/stdc++.h>
using namespace std;
  string cad,com;
  int j,cont,N;
int main ()
{
    cin>>N;
    for(int k = 0; k < N; k++){
    cin>>cad>>com;
     for(int i = 0; i < cad.size() ; i++)
     {
         if(cad[i] == com[j])
            cont++;
             j++;
     }
       cout<<cad.size() - cont<<endl;
       cont = 0;
       j = 0;
    }
    return 0;
}

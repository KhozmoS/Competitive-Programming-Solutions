#include <bits/stdc++.h>

using namespace std;
const int MAX = 10000;
bool A[MAX];
int x,cont ;
string cad;
int main()
{
    //ios_basesync_with_stdio(0); cin.tie(0);
  int n;
  cin>>n;
   for(int i = 0;i < n; i++)
   {
       cin>>cad;
       for(int j = 0; j < cad.size() ; j++)
       {
          A[cad[j] - '0'] = true;
       }
       for(int j = 0; j < MAX ;j++)
       {
          if(A[j] == true){
            cont++;
            A[j] = false;
          }
       }
       cout<<cont<<"\n";
        cont = 0;
   }
    return 0;
}

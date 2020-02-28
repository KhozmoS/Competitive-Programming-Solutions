#include<bits/stdc++.h>

using namespace std;
  //int n ;
  string cad , cadb;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>cad>>cadb;
     cad = cad + cadb;
     cadb = cad;
    reverse(cad.begin() , cad.end());
     if(cad == cadb)
        cout<<"Yes\n";
     else
        cout<<"No\n";
    return 0;
}

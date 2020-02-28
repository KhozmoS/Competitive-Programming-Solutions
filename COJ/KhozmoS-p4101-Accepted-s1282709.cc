#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n , r;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;

         string cad;
         cin>>cad;
         int y = 0 , n = 0 , in = 0;
         for(int i = 0 ; i < cad.size() ; i++)
         {
             y += cad[i]=='P';
             n += cad[i]=='N';
             in += cad[i]=='I';
         }
         if(y>n+in) cout<<"SI\n";
         else if(n>=y+in) cout<<"NO\n";
         else cout<<"INDECISOS\n";

}

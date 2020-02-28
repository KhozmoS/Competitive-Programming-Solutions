#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   string a;
   int t;cin>>t;
   while(t--){
       cin>>a;
       int sza = a.size();
       bool ok;
       for(int sz = 1 ; sz <= sza/2 ; sz++)
          if(sza % sz == 0){
             ok = true;
             for(int i = 0 ; i + sz <= sza ; i += sz)
                ok = (a.substr(i , sz) == a.substr(0 , sz) && ok ? true : false);
             if(ok){
                cout<<sz<<"\n";
                break;
             }
          }
       if(!ok)   cout<<sza<<"\n";
   }
}

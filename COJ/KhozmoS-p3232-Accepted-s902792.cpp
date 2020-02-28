#include <bits/stdc++.h>
#define MAXN 305

using namespace std;
int men = MAXN , conta , cont , N ,mi;
vector<int>v;
string V;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     cin>>N;
     for(int i = 0 ; i < N ; i++)
     {
         cin>>mi>>V;
         if(V != "AC")
         {
             v.push_back(mi);
         }
         else
         {
            conta++;
            if(men > mi)
                men = mi;
            v.push_back(mi);
         }
     }
      sort(v.begin(), v.end());
       if(conta == 0)
        cout<<0<<"\n";
       else{
      for(int i = 0 ; v[i] != men ; i++){
        cont++;
      }
        cout<<(cont * 20) + men<<"\n";
       }
    return 0;
}

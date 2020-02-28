#include <bits/stdc++.h>


using namespace std;

const int MAX = 1e5 + 5;
const int mod = 1e9 + 7;

map <int , int> m;
int t , n , ar[MAX] , par[MAX] , impar[MAX];

void update(int pos , int cant , bool flag)
{
    if(flag)
        for(int i = pos ; i < MAX ; i += (i & -i))
           par[i] = (par[i] + cant) % mod;
    else
        for(int i = pos ; i < MAX ; i += (i & -i))
           impar[i] = (impar[i] + cant) % mod;
}
int query(int pos , bool flag)
{
    int res = 0;
    if(flag)
        for(int i = pos ; i > 0 ; i -= (i & -i))
          res = (res + par[i]) % mod;
    else
        for(int i = pos ; i > 0 ; i -= (i & -i))
          res = (res + impar[i]) % mod;

   return res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;

    int br[MAX];
    while(t--)
    {

       cin>>n;
       for(int i = 0 ; i < n ; i++) {cin>>ar[i]; br[i] = ar[i];}
       sort(br , br + n);
       int ll = 1;
       for(int i = 0 ; i < n ; i++)
       {
           if(m.find(br[i]) == m.end()){
              m[br[i]] = ll;
              ll++;
           }
       }
       //for(int i = 0 ; i < n ; i++) cout<<m[ar[i]]<<"\n";

       for(int i = 0 ; i < n ; i++)
       {
         int num = m[ar[i]];
         if(ar[i] % 2 == 0)
         {
            int u = query(num , true);
            int v = query(num , false);
            //cout<<u<<" "<<v<<" "<<num<<"\n";

            update(num + 1, u + 1 , true);
            update(num + 1, v , false);
         }
         else
         {
           int u = query(num , true);
           int v = query(num , false);

            update(num + 1, u + 1 , false);
            update(num + 1, v , true);
         }
       }

       cout<<query(MAX - 3 , false)<<"\n";
       m.clear();
       for(int i = 0 ; i < MAX ; i++) par[i] = 0 , impar[i] = 0;
    }

    return 0;
}

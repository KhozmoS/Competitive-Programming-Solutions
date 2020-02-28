#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map <ll , int> A;
map <ll , int> B;

ll pot[65];
int ta = 0;
ll to_num(string x)
{
    reverse(x.begin() , x.end());  ta = x.size();
    ll res = 0;
    for(int i = 0 ; i < ta - 1 ; i++)
         if(x[i] == '0')
            res += pot[i];

    return res;
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   pot[0] = 1;
   for(int i = 1 ; i <= 60 ; i++) pot[i] = pot[i - 1] * 2ll;

   int t; cin>>t;
   set <ll> S1;
   set <ll> S2;
   while(t--)
   {
       string cad; cin>>cad;
       ll x = to_num(cad);
       if(cad[0] == '0'){ A[x]++; S1.insert(x);}
       else {B[x]++; S2.insert(x);}

   }
   int marr = 0; int fiend = 0;
   ll big = 0;
   for(int i = 0 ; i < ta - 1 ; i++) big += pot[i];
   set <ll , int> ::  iterator it;
   for(it = S1.begin() ; it != S1.end() ; it++){
       if(S2.find(big - *it) != S2.end())
          marr += A[*it] * (B[big - *it]);
       if(S1.find(big - *it) != S1.end())
          fiend += (A[*it] * (A[big - *it]));
   }
   fiend >>= 1;
   int fie = 0;
   for(it = S2.begin() ; it != S2.end() ; it++)
       if(S2.find(big - *it) != S2.end()){
          fie += B[*it] * (B[big - *it]);
       }
   fie >>= 1;

   cout<<fiend + fie<<" "<<marr<<"\n";
    return 0;
}

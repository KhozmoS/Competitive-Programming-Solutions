#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
set <ll> mk;
vector <ll> ans;
int main()
{
        ios_base::sync_with_stdio(0);cin.tie(0);
        ans.push_back(1);
        for(ll j = 2 ; j <= 32 ; j++)
          for(ll i = 2 ; i <= 100000 && (ll)(pow(i , j)) <= 1000000000ll ; i++){
             ll x = pow(i , j);
             if(mk.find(x) == mk.end()){
                ans.push_back(x);
                mk.insert(x);
             }
          }
        sort(ans.begin() , ans.end());
       // ans.push_back(1000000001);
        //cout<<ans.size()<<"\n";
   //    cout<<ans[ans.size()-1]<<"\n";
  //     for(int i = 2 ; i <= 16 ; i++)cout<<ans[i]<<" ";
       int t;cin>>t;

       for(int cas = 1 ; t-- ; cas++)
       {
           int a , b;cin>>a>>b;

           int hi = upper_bound(ans.begin() , ans.end() , b) - ans.begin();
           int lo = lower_bound(ans.begin() , ans.end() , a) - ans.begin();
          // cout<<hi<<" "<<lo<<" "<<ans[lo]<<" "<<ans[hi]<<"\n";
           cout<<"Case "<<cas<<": "<<hi-lo<<"\n";
       }
}

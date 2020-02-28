#include <bits/stdc++.h>

using namespace std;

typedef pair <int , int> ii;
typedef long long ll;
const ll mod = 1000000007;
const int MAX = 1e6+5;
int n,pos;

map <int , int> mp;
bool mk[26];

string ar;
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int n;
   cin>>n;
   ll ans = 0;
   ar.reserve(500005);
   for(int i = 0 ; i < n ; i++)
   {
       cin>>ar;
       for(int j = 0 ; j < ar.size() ; j++)
       {
           if(mk[ar[j]-'a']) mk[ar[j]-'a'] =false;
           else mk[ar[j]-'a'] = true;
       }
       int nm = 0;
       for(int j = 0 ; j < 26 ; j++)
            if(mk[j]) nm += (1<<j);
      // cout<<nm<<"\n";
       if(mp.find(nm)!=mp.end())ans += mp[nm];
       for(int j = 0 ; j < 26 ; j++){
            if(mk[j] && mp.find(nm^(1<<j))!=mp.end())
                ans += mp[nm^(1<<j)];
            else if(!mk[j] && mp.find(nm^(1<<j))!=mp.end())
                ans += mp[nm^(1<<j)];
            mk[j] = false;
       }
       mp[nm]++;
      // cout<<ans<<" "<<i<<"\n";
   }
   printf("%lld\n" , ans);

}

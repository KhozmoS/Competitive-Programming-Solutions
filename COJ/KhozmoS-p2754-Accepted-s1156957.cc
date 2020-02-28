#include <bits/stdc++.h>

using namespace std;
#define PB push_back
const int MAX = 1e5;
bool mk[MAX];
string cad;
vector <int> v;
bool ok(string x)
{
    string y = x;
     reverse(x.begin() , x.end());
    return x == y;
}
int dp[MAX];

int F(int mask)
{
    if(!mask) return 0;

    if(dp[mask]) return dp[mask];
    int res = 1e9;
    for(int i = 0 ; i < v.size() ; i++){
        if((v[i] & mask) == v[i])
        res = min(res , F((mask ^ v[i])) + 1);
    }
    return dp[mask] = res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
   //cout<<(3 ^ 3)<<"\n";
   while(cin>>cad){
   v.clear();     
   memset(dp , 0 , sizeof(dp));
   int sz = cad.size();
   for(int mask = 1 ; mask < (1 << sz) ; mask++){
         string curr = "";
       for(int i = 0 ; i < sz ; i++)
         if(mask & (1 << i))
           curr += cad[i];
       if(ok(curr)){
         // cout<<curr<<"\n";
          v.PB(mask);
       }
   }
    cout<<F((1<<sz)-1)<<"\n";
   }
}


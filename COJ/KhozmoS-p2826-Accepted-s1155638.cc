#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 5;
int dp[MAX] , n;
map <string , bool> mk;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     cin>>n;

     for(int i = 0 ; i < n ; i++)
     {
         string x;cin>>x;
         mk[x] = true;
     }
     string cad;cin>>cad;
     int ta = cad.size();
     cad = " " + cad;
     dp[0] = 1;
     for(int i = 1 ; i <= ta ; i++)
     {
         for(int j = max(i - 20 , 1) ; j <= i ; j++)
         {
             string x = cad.substr(j , i - j + 1);
             //cout<<x<<"\n";
             if(mk.find(x) != mk.end())
                 dp[i] = (dp[i] + dp[j-1]) % mod;
         }
     }
     cout<<dp[cad.size() - 1]<<"\n";

}

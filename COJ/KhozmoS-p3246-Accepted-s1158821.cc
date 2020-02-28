#include <bits/stdc++.h>

using namespace std;

// 2 1 4 3    5
const int MAX = 100;
typedef long long ll;

ll P[MAX][MAX] , pot[MAX];
ll to_dec(string x)
{
    reverse(x.begin() , x.end());
    ll res = 0;
    for(int i = 0 ; i < x.size() ; i++)
        if(x[i] - '0')
          res += pot[i];
    return res;
}
void PASCAL()
{
    pot[0] = 1ll;
    for(int i = 1 ; i <= 65 ; i++)
       pot[i] = pot[i-1] * 2ll;
    for(int i = 0 ; i < MAX ; i++) P[i][0] = P[i][i] = 1ll;

    for(int i = 1 ; i < MAX ; i++)
        for(int j = 1 ; j < i ; j++)
           P[i][j] = (P[i-1][j] + P[i-1][j-1]);
}
ll imp[MAX] , p[MAX];
int main()
{
   ios_base::sync_with_stdio(0) ;cin.tie(0);
   PASCAL();
   imp[1] = 1;p[0] = 1;p[1] = 1;
   for(int i = 2 ; i < MAX ; i++){
      imp[i] = imp[i-1];
      for(int j = 1 ; j <= i ; j += 2)
         imp[i] += P[i-1][j-1];
   }
   for(int i = 2 ; i < MAX ; i++){
         p[i] = p[i-1];
       for(int j = 2 ; j <= i ; j += 2)
         p[i] += P[i-1][j-1];
   }
   //for(int i = 1 ; i < 11 ; i++)cout<<p[i]<<" "<<imp[i]<<"\n";
   ll n;while(cin>>n && n){if(n == 1){cout<<0<<"\n";continue;}
   string ans = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
   int cur = 0;
   while(n > 0)
   {
      int i = 1;
      if((cur & 1))
      {
         for(; imp[i] < n; i++)
            ;
         if(n == 1){
            ans[0] = '1',n=0;
            break;
         }
         else
         n = n - imp[i-1];
        // cout<<n<<"\n";
        // cout<<imp[i]<<" "<<i<<"\n";
         ans[i-1] = '1';
      }
      else{
        for(;p[i] < n ; i++)
            ;
         //cout<<p[i]<<"\n";
         if(n == 1){
            break;
         }
         n = n - p[i-1];
        // cout<<n<<"\n";
       //  cout<<p[i]<<"\n";
         ans[i-1] = '1';
      }
      cur++;
   }
   reverse(ans.begin() , ans.end());
   string tod = "";
   bool flag = false;
   for(int i = 0 ; i < ans.size() ; i++){
     if(ans[i] == '1') flag = true;
     if(flag) tod += ans[i];
   }
   cout<<to_dec(tod)<<"\n";
   }
}

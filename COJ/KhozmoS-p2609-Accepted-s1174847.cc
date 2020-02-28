#include <bits/stdc++.h>

using namespace std;

int memo[1005][1005];
vector <int> p[1005];
bool dp(int i , int j)
{
    if(j == 1){
        memo[i][j] = true;
        return true;
    }
    if(j == i) return false;

    if(memo[i][j] != -1) return memo[i][j];
    if(memo[j][i] != -1) return memo[j][i];

    for(int k = 0 ; k < p[j].size() ; k++)
        memo[i][j] = max(memo[i][j] , (int)dp(i , p[j][k]));

    return memo[i][j];
}
int main()
{
   memset(memo , -1 , sizeof(memo));
   int n , m;cin>>n>>m;

   while(m--)
   {
       int a , b;
       cin>>a>>b;
       p[b].push_back(a);
   }
   int ans = 0;
   for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j < i ; j++)
            dp(j , i);

   for(int i = 1 ; i <= n ; i++)
        for(int j = i+1 ; j <= n ; j++)
            if(memo[i][j] == 1) ans++;


   cout<<ans<<"\n";
}

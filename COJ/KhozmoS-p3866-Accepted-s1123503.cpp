#include <bits/stdc++.h>

using namespace std;
const int MAX = (1e5 + 3) * 2;

typedef long long ll;

map <int , ll> dp;
bool is_prime(int n)
{
    if(n == 2) return true;
    if(n % 2 == 0 || n == 1 || n == 0) return false;


    for(int i = 3 ; i * i <= n ; i += 2)
        if(!(n % i)) return false;


    return true;
}
ll F(int n)
{
    if(is_prime(n))
        return 1;

    if(dp.find(n) != dp.end()) return dp[n];

    for(int i = 2 ; i * i <= n ; i++)
        if(!(n % i)){
         if(dp.find(n) != dp.end())
             return dp[n] = ((F(i) * F(n / i)) + dp[n]);
         else
         return dp[n] = (F(i) * F(n / i));
        }

    return 1;
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        cout<<(int)log2(n) + 1<<"\n";
    }

    return 0;
}

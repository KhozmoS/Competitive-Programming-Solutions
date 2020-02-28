#include <bits/stdc++.h>

using namespace std;

string cad;
int dp[1005];
int ta;
bool is_pal(string x)
{
    string y = x;
    reverse(x.begin() , x.end());
    return x == y;
}
int F(int pos)
{
    if(ta == pos) return 0;
    if(ta - 1 == pos) return 1;

    if(dp[pos] != -1) return dp[pos];

    string s = "";
    int res = 1001;
    for(int i = pos ; i < ta ; i++)
    {
        s += cad[i];
        if(is_pal(s))
        res = min(res ,F(i + 1) + 1);
    }
    return dp[pos] = res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp , -1 , sizeof(dp));
    cin>>cad;
    ta = cad.size();
    cout<<F(0)<<"\n";

    return 0;
}

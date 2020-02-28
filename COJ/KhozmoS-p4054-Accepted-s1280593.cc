#include <bits/stdc++.h>

using namespace std;

map <string , int> dp;

int n;

int F(string &x)
{
    if(x.size()==1 || !x.size()) return 0;

    if(dp.find(x) != dp.end()) return dp[x];

    int res = INT_MAX;

    for(int i = 0 ; i < x.size() ; i++)
    {
        int cur = 0;

        int sml = 0;

        string left = "";

        for(int j = i-1 ; j >= 0 ; j--)
        {
            left = x[j]+left;
            sml += (x[j]==x[i]);
        }

        cur = sml + F(left);
        int smr = 0;
        string right = "";
        for(int j = i+1 ; j < x.size() ; j++)
        {
            right = right + x[j];
            smr += x[j]==x[i];
        }
        cur += smr + F(right);

        res = min(res, cur);
    }
    return dp[x]=res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        dp.clear();
        cin>>n;
        string cad;cad.reserve(55);
        cin>>cad;
        cout<<F(cad)<<"\n";
    }

}

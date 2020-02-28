#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int s , c , in1 , in2;
typedef pair <int , int> II;
vector <II> dp; int ans1 , ans2;
bool flag;

int find_it(int x)
{
    int in = -1; int fn = 1000000;
    while(in+1<fn)
    {
        int mt = (in+fn) >> 1;
        if(dp[mt].first >= x)
            fn = mt;
        else
            in = mt;
    }
    return ((dp[fn].first == x) ? fn : -1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int cas = 1;
    while(cin>>s>>c>>in1>>in2)
    {
    if(!s && !c) break;
    dp.clear();
    flag = false;
    if(!in1) in1 = s;
    if(!in2) in2 = c;

    for(int k = 0 ; k <= 1000000 ; k++)
        dp.push_back(II((s*k) + (s-in1) , k));

    for(int k = 0 ; k <= 1000000 ; k++)
    {
        ans2 = (((int)(c))*k) + (c - in2);
        if(find_it(ans2) != -1)
        {
            ans1 = find_it(ans2);
            flag = true;
            break;
        }
    }
    if(flag){
        cout<<"Case "<<cas++<<": ";
        cout<<dp[ans1].second<<" "<<ans2%s<<"/"<<s<<"\n";
    }
    else{
        cout<<"Case "<<cas++<<": ";
        cout<<"Never\n";
    }
    }
}

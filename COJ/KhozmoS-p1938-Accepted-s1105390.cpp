#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAX = 1e6 + 5;
bool mk[MAX];

void criba()
{
    for(int i = 2 ; i * i < MAX ; i++)
        if(!mk[i])
            for(int j = i * i ; j < MAX ; j += i)
              mk[j] = true;

}
vector <ll> ans;
void sol()
{
    for(ll i = 2 ; i < MAX ; i++)
        if(!mk[i])
            for(ll j = (i) ; j < (MAX * MAX) ; j *= (ll)i)
              if(j != i)
              ans.push_back(j);

}
int main()
{
    criba();
    sol();
    ios_base::sync_with_stdio(0);cin.tie(0);
   // cout<<ans.size();
  // cout<<ans[0]<<" "<<ans.size();
    int t;
    int len = ans.size();
    cin>>t;
    while(t--)
    {
        ll low , hig;
        int res = 0;
        cin>>low>>hig;
        for(int i = 0 ; i < len ; i++)
            if(ans[i] >= low && ans[i] <= hig)
                res++;

        cout<<res<<"\n";
    }
    return 0;
}

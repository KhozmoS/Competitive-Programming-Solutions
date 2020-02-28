#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 1e5+6;
const ll mod = 1e9+7;

int sz , pos[28];
int dp[MAX][27];

int exp(ll a , ll b)
{
    ll res = 1;

    while(b)
    {
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}
ll pot[MAX];

int F(int last , int cnt)
{

    if(cnt-1==sz)
    {
        --cnt;
        if(cnt&1)
            return last!=(sz);
        else
            return last==sz;
    }
    ll res = 0;
    //cout<<"wa\n";
    if(last > -1 && dp[last][cnt]!=-1){
        //cout<<"wa\n";
        return dp[last][cnt];
    }
    //cout<<last<<"\n";

    for(int i = 0 ; i < 26 ; i++)
    {
        if(last >= pos[i] || pos[i] == sz) {
            //cout<<res<<"\n";
            if(cnt%2==0)
                    res += pot[sz-cnt];
            //cout<<res<<"\n";
            continue;
        }

        if(pos[i] == (sz-1))
        {
        //    cout<<"wa\n";

            if(cnt&1){
                //cout<<sz<<" "<<cnt<<"\n";
                    res += pot[sz-cnt];
            }

            continue;
        }


        res += F(pos[i],cnt+1) + (cnt&1);
    }

    if(last>-1)
        return dp[last][cnt]=res%mod;

    return res%mod;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp,-1,sizeof(dp));
    pot[0] = 1ll;
    for(int j = 0 ; j < MAX ; j++)
        pot[j] = (pot[j-1] + exp(26,j))%mod;

    string cad;
    cin>>sz;
    cin>>cad;
    sz = cad.size();


    for(int i = 0 ; i < 26 ; i++)
    {
        pos[i] = sz;
        for(int j = 0 ; j < sz ; j++)
            if(cad[j]-'a'==i)
                pos[i] = j;
    }

    cout<<F(-1,1)<<"\n";
}

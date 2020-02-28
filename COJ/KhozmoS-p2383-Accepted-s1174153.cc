#include<bits/stdc++.h>


using namespace std;
#define PB push_back
typedef unsigned long long ll;
typedef vector <ll> vi;
const ll MAX = 1000000000;
ll exp(ll a , ll b)
{
    if(!b) return 1;
    if(b ==1) return a;
    ll p = exp(a , b/2);
    return (b&1 ? p*p*a : p*p);
}

bool is(ll x)
{
   if(!x) return true;
   if(x == 2) return true;
   if(x % 2 == 0) return false;
   if(x == 1) return false;
   for(int i = 3 ; i * i <= x ; i += 2)
        if(x % i == 0)
            return false;
   return true;
}
set <ll> S;
vi ans;
void Right(ll x)
{
    if(!is(x) || x > MAX)
        return;
    if(S.find(x) == S.end()){
        ans.PB(x);
        S.insert(x);
    }
    for(ll i = 1 ; i <= 9 ; i++)
        Right(x*10+i);
}
void Left(ll x , int cnt)
{
    if(!is(x) || x > MAX)
        return;
    if(S.find(x) == S.end()){
        ans.PB(x);
        S.insert(x);
    }
    for(ll i = 1 ; i <= 9 ; i++)
        Left(i * exp(10 , cnt) + x , cnt+1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    Right(0);
    Left(0 , 0);
    sort(ans.begin() , ans.end());

    int t;cin>>t;

    while(t--)
    {
        ll a , b;
        cin>>a>>b;
        int lo = lower_bound(ans.begin() , ans.end() , a) - ans.begin();
        int hi = upper_bound(ans.begin() , ans.end() , b) - ans.begin();
        cout<<hi-lo<<"\n";
    }
}

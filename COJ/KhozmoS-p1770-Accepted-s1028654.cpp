#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll , ll > par;
const int mod = 10000;

 ll solq , a , b;
int U , Q;
vector <par> upd;
vector <par> quer;
ll form(ll x)
{
    if(x % 2 == 0)
    {
       ll y = x / 2;
       return ((y % mod) * ((x + 1) % mod)) % mod;
    }
     ll y = (x + 1) / 2;
     return ((y % mod) * ((x) % mod)) % mod;
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n>>U>>Q;
    for(int i = 0 ; i < U ; i++)
    {
        cin>>a>>b;
        //if(a > n || b > n) continue;
        par p; p.first = a; p.second = b;
        upd.push_back(p);
    }
    for(int i = 0 ; i < Q ; i++)
    {
        cin>>a>>b;
        if(a > b)
        swap(a , b);

        a--;
        ll sum = 0;

        for(int j = 0 ; j < U ; j++)
        {
            ll nb = a;
            ll na = b;
            if(a + 1 > upd[j].second){
            //cout<<a + 1<<"\n";
            continue;
            }
            if(na >= upd[j].first)
            {
               if(na >= upd[j].second)
               na = upd[j].second;

              //cout<<"this b"<<" "<<b<<"\n";
              ll x = (na - upd[j].first) + 1;
              //cout<<upd[j].first<<"\n";
              ll m = form(x);
              sum = ((sum % mod) + (m % mod)) % mod;
              //cout<<j<<" "<<sum<<"\n";
              if(a >= upd[j].first)
              {
              if(a >= upd[j].second)
              nb = upd[j].second - 1;

              x = nb - upd[j].first + 1;
              ll s = form(x);
              sum = (sum - s + mod) % mod;
              }
            }
        }
       cout<<sum<<"\n";
    }
    return 0;
}

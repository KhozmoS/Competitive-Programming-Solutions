#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int MAX = 1e5 + 5;
ll bas = 113 , H[MAX] , P[MAX];
typedef pair <ll , int> par;
map <par , ll> freq;

string cad;

ll calc_hash(int s, int e){return (( H[e] - (H[s] * P[e-s]) % mod + mod) % mod);}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n  ,q , len;
    while(cin>>n>>q>>len){
    while(n--)
    {
        cin>>cad;
        H[0] = 0;
        P[0] = 1;
        for(int i = 1 ; i <= len ; i++){
          H[i] = (H[i - 1] * bas + (cad[i - 1] - 'a' + 1)) % mod;
          P[i] = (P[i - 1] * bas) % mod;
        }
        for(int i = 1 ; i <= len ; i++)
        {
             //ll ind = i;
             ll ind = (H[i - 1] * P[len - i]) % mod;

            //ind *= 10;
            ind = (ind + calc_hash(i , len)) % mod;
            //cout<<calc_hash(i , len)<<"\n";
            //cout<<ind<<" "<<i<<"\n";
            par p = par(ind , i);
            freq[p]++;
        }
        //cout<<H[len]<<"end\n";
    }
    while(q--)
    {
       ll ans = 0;
       cin>>cad;
        H[0] = 0;
        P[0] = 1;
        for(int i = 1 ; i <= len ; i++){
          H[i] = (H[i - 1] * bas + (cad[i - 1] - 'a' + 1)) % mod;
          P[i] = (P[i - 1] * bas) % mod;
        }
           //cout<<"now\n";
        for(int i = 1 ; i <= len ; i++)
        {
             //ll ind = i;
             ll ind = (H[i - 1] * P[len - i]) % mod;
             //ind %= mod;
          //  ind *= 10;

            ind = (ind + calc_hash(i  , len)) % mod;
         //   cout<<ind<<" "<<i<<"\n";
            par p = par(ind , i);
            ans += freq[p];
        }
        cout<<ans<<"\n";
    }
    freq.clear();
    }
    return 0;
}

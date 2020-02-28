#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int> ii;
typedef pair <ii , int> iii;
typedef vector <int> vi;
typedef vector < vi > vvi;
typedef vector < ii > vii;
typedef vector < vii > vvii;

const int mod = 1e9+7;
const int MAX = 1e6+5;

ll n;
string in;
ll op;
ll fact[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    fact[0] = 1;
    for(int i = 1 ; i < MAX ; i++)
        fact[i] = fact[i-1] * i % mod;
    ll ans = 1;
    cin>>n>>in;
    for(int i = 0 ; i < sz(in) ; i++)
    {
        if(in[i]=='N')
            op++;
        else{
            ans = (op * ans) % mod;
            op--;
        }
    }

    cout<<ans * fact[n] % mod<<"\n";
}

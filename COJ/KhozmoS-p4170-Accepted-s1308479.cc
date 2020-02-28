#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()

typedef long long ll;
typedef pair <int , int> ii;
typedef pair <ii , int> iii;
typedef vector <int >vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+7122153;
const int MAX = 1e6+5;


ll H[MAX] , B = 101111123;
ll H1[MAX];

ll P[MAX];
int ans1, ans2 , n;
vector <int> ans3;
set <ll> S;
ll ar[MAX];
ll calc(int a , int b)
{
    return (H[b] - (H[a-1]*P[b-a+1]%mod) + mod) %mod;
}
ll calc1(int a , int b)
{
    return (H1[a] - (H1[b+1]*P[b-a+1]%mod) + mod) %mod;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    P[0] = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        ll cur;cin>>cur;
        ar[i] = cur;
        P[i] = (P[i-1] * B) % mod;
        H[i] = ((H[i-1] * B % mod) + cur) % mod;
    }
    for(int i = n ; i >= 1 ; i--)
    {
        H1[i] = ((H1[i+1] * B % mod) + ar[i]) % mod;
    }
    for(int k = 1; k <= n ; k++){
        for(int i = 1 ; i + k - 1 <= n ; i += k)
        {
            ll tmp = calc(i , i+k-1);
            ll tmp1 = calc1(i , i+k-1);
            if((S.find(tmp1) == S.end()) && (S.find(tmp) == S.end()))
            {
                S.insert(tmp);
            }
        }
        if(sz(S)==ans1)
        {
            ans2++;
            ans3.pb(k);
        }
        else if(sz(S)>ans1)
        {
            ans1 = sz(S);
            ans2 = 1;
            ans3.clear();
            ans3.pb(k);
        }
        S.clear();
    }
    cout<<ans1<<" "<<ans2<<"\n";
    for(int i = 0 ; i < sz(ans3) ; ++i) cout<<ans3[i]<<(i==(ans2-1) ? "\n" : " ");
}

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()

typedef long long ll;
typedef pair <ll , ll> ii;
typedef pair <ii , int> iii;
typedef vector <int >vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+21;
const ll mod1 = 1e9+33;
const int MAX = 1e6+5;


ll H[MAX] , B = 1e7+103;
ll H2[MAX] , B1 = 1e9+7;
ll H1[MAX];
ll H3[MAX];

ll P[MAX];
ll P1[MAX];
int ans1, ans2 , n;
vector <int> ans3;
set <ii> S;
ll ar[MAX];
ll calc(int a , int b)
{
    return (H[b] - (H[a-1]*P[b-a+1]%mod) + mod) %mod;
}
ll calc2(int a , int b)
{
    return (H2[b] - (H2[a-1]*P1[b-a+1]%mod1) + mod1) %mod1;
}
ll calc1(int a , int b)
{
    return (H1[a] - (H1[b+1]*P[b-a+1]%mod) + mod) %mod;
}
ll calc3(int a , int b)
{
    return (H3[a] - (H3[b+1]*P1[b-a+1]%mod1) + mod1) %mod1;
}
bool isp(int x)
{
    for(int i = 2 ; i*i <= x; i++) if(x%i==0) return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    P[0] = 1;
    P1[0] = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        ll cur;cin>>cur;
        ar[i] = cur;
        P[i] = (P[i-1] * B) % mod;
        P1[i] = (P1[i-1] * B1) % mod1;
        H[i] = ((H[i-1] * B % mod) + cur) % mod;
        H2[i] = ((H2[i-1] * B1 % mod1) + cur) % mod1;
    }
    for(int i = n ; i >= 1 ; i--)
    {
        H1[i] = ((H1[i+1] * B % mod) + ar[i]) % mod;
        H3[i] = ((H3[i+1] * B1 % mod1) + ar[i]) % mod1;
    }
    for(int k = 1; k <= n ; k++){
        for(int i = 1 ; i + k - 1 <= n ; i += k)
        {
            ll tmp = calc(i , i+k-1);
            ll tmp2 = calc2(i , i+k-1);
            ll tmp3 = calc3(i , i+k-1);
            ll tmp1 = calc1(i , i+k-1);
            if((S.find(ii(tmp,tmp2)) == S.end()) && (S.find(ii(tmp1,tmp3)) == S.end()))
            {
                S.insert(ii(tmp,tmp2));
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

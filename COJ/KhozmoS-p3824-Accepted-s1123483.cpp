#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair <int , int> par;
const int MAX = 1e6 + 5;
vector <ll> prime;
vector <par> F;
bool mk[MAX];
ll n;
ll op(ll p , ll e)
{
    e++;
    ll pot = 1;
    while(e--) pot *= p;

    pot--;
    return pot / (--p);
}
void solve()
{
    ll N = n;
    for(int i = 0 ; prime[i] * prime[i] <= n ; i++)
    {
        int exp = 0;ll pr = prime[i];
        if(n % pr == 0)
        {
           while(n % pr == 0)
           {
             exp++;
             n /= pr;
           }
           par p = make_pair((int)pr , exp);
           F.push_back(p);
        }
    }
    if(n > 1)
        F.push_back(make_pair(n , 1));

    ll sum = 1;

    for(int i = 0 ; i < F.size() ; i++)
        sum *= op((ll)F[i].f , (ll)F[i].s);
        F.clear();
    sum -= N;
    if(sum == N)cout<<"perfect\n";
    else if(sum > N)cout<<"abundant\n";
    else cout<<"deficient\n";

}
void criba()
{
    for(int i = 4 ; i < MAX ; i += 2) mk[i] = true;

    for(int i = 3 ; i * i < MAX ; i += 2)
        if(!mk[i])
        for(int j = i * i ; j < MAX ; j += i)
           mk[j] = true;

    prime.push_back(2);

    for(ll i = 3 ; i < MAX ; i += 2)
        if(!mk[i])
          prime.push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     criba();
    int t;
    cin>>t;
    while(t--)
       cin>>n , solve();
    return 0;
}

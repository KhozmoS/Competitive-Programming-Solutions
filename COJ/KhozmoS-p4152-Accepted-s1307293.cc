#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()

typedef long long ll;
typedef pair<int , int > ii;
typedef vector <int> vi;

const ll mod = 1e9+7;
const int MAX = 1e6+7;
int ar[MAX*5];

ll A , B , K;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll ans = 0;
    cin>>A>>B>>K;
    if(min(A,B)<K)
    {
        cout<<ans<<"\n";
        return 0;
    }
    if(B>=K){
        ans += (ll)(A/K);
        B-=K;
    }
    if(min(A,B)<K)
    {
        cout<<ans<<"\n";
        return 0;
    }
    if(B>=K){
        ans += (ll)(A/K);
        B-=K;
    }
    if(min(A,B)<K)
    {
        cout<<ans<<"\n";
        return 0;
    }
    if(A>=K){
        ans += (ll)(B/K);
        A-=K;
    }
    if(min(A,B)<K)
    {
        cout<<ans<<"\n";
        return 0;
    }
    if(A>=K){
        ans += (ll)(B/K);
        A-=K;
    }
    if(min(A,B)<K)
    {
        cout<<ans<<"\n";
        return 0;
    }
    cout<<ans<<"\n";
}

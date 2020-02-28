#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back
#define db double
const int MAX = 1e6+5;

typedef long long ll;
typedef pair <int , int> par;
typedef pair <par , int> trio;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    ll sm = 0;
    for(int i = 1 ; i < n ; i++)
    {
        ll x;cin>>x;
        sm += x;
    }
    cout<<((ll)n*(n+1)/2ll)-sm<<"\n";
}

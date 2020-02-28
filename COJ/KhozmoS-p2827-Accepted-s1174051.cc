#include<bits/stdc++.h>


using namespace std;
#define PB push_back
const int mod = 10007;

typedef unsigned long long ll;
typedef vector <ll> vi;

vi F;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    F.PB(0);
    F.PB(1);
    F.PB(2);
    int id = 3;
    while(F[id-1] <= (ll)1e18)
        F.PB(F[id-1] + F[id-2]) , id++;

    ll n;
    while(cin>>n)
    {
        stack <ll> pila;
        ll ans = n;
        while(n > 0)
        {
            vi :: iterator it = upper_bound(F.begin() , F.end() , n);
            --it;
            n -= *it;
            pila.push(*it);
        }
        cout<<ans<<" = ";
        while(!pila.empty())
        {
           ll out = pila.top();
           pila.pop();
           cout<<out<<(pila.empty() ? "\n" : " + ");
        }
    }
}

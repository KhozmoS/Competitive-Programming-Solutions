#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 1e6+5;
#define PB push_back

vector <ll> specials;

void F(ll cur , int sz , int last)
{
    if(sz==11) return;
    specials.PB(cur);

    if(last) F(cur*10+last-1 , sz+1 , last-1);

    if(last!=9) F(cur*10+last+1 , sz+1 , last+1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 1 ; i <= 9 ; i++)
        F(i , 1 , i);
    sort(specials.begin() , specials.end());

    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        int pos = upper_bound(specials.begin() , specials.end() , n) - specials.begin();
        cout<<specials[pos]<<"\n";
    }
}

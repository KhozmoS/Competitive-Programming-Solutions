#include <bits/stdc++.h>

using namespace std;


typedef unsigned long long ll;
ll pot[65];
ll ta[65];

ll f(ll x)
{
    if(!x) return 0;
    if(x == 1) return 1;

    int i = 0;
    while(pot[i] <= x)
        i++;
    i--;
    ll s = 0;
    if(i)
        s = ta[i-1];
    s += (x - pot[i] + 1);


    return s + f(x - pot[i]);
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pot[0] = 1;
  ta[0] = 1;
  for(ll i = 1 ; i <= 54  ; i++){
        pot[i] = (pot[i-1] * 2ll);
        ta[i] += ta[i-1] + (pot[i] + ta[i-1]);
  }


  ll a, b;
  cin>>a>>b;//>>b;
  ll ta = f(a-1);
  ll tb = f(b);
  cout<<tb-ta<<"\n";
}

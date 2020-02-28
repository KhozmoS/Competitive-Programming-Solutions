#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k , d;

ll f(ll e)
{

    return ((log10(k)) * e) + 1ll;
}

int main()
{
    //k = 2;
    //cout<<f(10);
  // ios_base::sync_with_stdio(0);cin.tie(0);
     cin>>k>>d;

     ll in = 1; ll fn = 1e10;
     while((fn - in) > 3)
     {
         ll mt = (fn + in) >> 1;
         ll v = f(mt);
         if(v >= d)
            fn = mt;
         else
            in = mt;
     }
     for(; in <= fn ; ++in)
     if(f(in) >= d){ cout<<in<<"\n"; return 0;}


}

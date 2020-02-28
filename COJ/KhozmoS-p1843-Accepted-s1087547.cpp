#include <bits/stdc++.h>
using namespace std;
typedef int ll;

map <ll , bool> mk;

set <ll> con;
set <ll> :: iterator it;
  ll t = 1;

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i = 1 ; i <= 1e5 ; i++)
  {
     con.insert(i * i);
     mk[t] = true;
     t += i;
  }
  ll a , b;
  int cas = 1;
  while(cin>>a>>b && a || b)
  {
    it = con.lower_bound(a + 1);
    int ans = 0;
    while(*it < b)
    {
        if(mk[*it])
            ans++;
        it++;
    }
    cout<<"Case "<<cas++<<": "<<ans<<"\n";
  }
	return 0;
}

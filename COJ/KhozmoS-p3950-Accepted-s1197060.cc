#include <bits/stdc++.h>

using namespace std;

int n , k;
const int MAX = 1e6;
string ar[MAX];
int SZ[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string cad;
    cin>>n>>k;for(int i = 0 ; i < n ; i++){cin>>ar[i];SZ[i] = ar[i].size();}

    while(k--)
    {
        cin>>cad;
        int sz = cad.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
          if(sz <= SZ[i])
            ans += (cad == (ar[i].substr(SZ[i]-sz , sz)));
        }cout<<ans<<"\n";
    }

}

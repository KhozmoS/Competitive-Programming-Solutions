#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map <string , ll> mp;
map <string , bool > mk;
vector <string> v;
int n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 0 ; i < n ; i++)
    {
        string cad;cin>>cad;
        v.push_back(cad);
        mp[cad]++;
    }
    ll ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int k = 0 ; k < v[i].size() ; k++){
            string cad = "";
            for(int j = k ; j < v[i].size() ; j++)
            {
                cad += v[i][j];
                if(!mk[cad]){
                    ans += mp[cad];
                    mk[cad] = true;
//cout<<cad<<"\n";
                }
            }
        }
        ans--;
       // cout<<"nwww\n";
        mk.clear();
    }
    cout<<ans<<"\n";
}

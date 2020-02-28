#include <bits/stdc++.h>

using namespace std;

string cad;

map <pair <int , int> , int> mp;

int ab = 150001;
int ac = 150001;

long long ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>cad;
    mp[make_pair(ab , ac)]++;
    for(int i = 0 ; i < cad.size() ; i++)
    {
        if(cad[i] == 'a') ab++ , ac++;
        if(cad[i] == 'b') ab--;
        if(cad[i] == 'c') ac--;

        if(mp.find(make_pair(ab , ac)) != mp.end())
            ans += (long long)mp[make_pair(ab , ac)];
        mp[make_pair(ab , ac)]++;
    }
    cout<<ans<<"\n";
}


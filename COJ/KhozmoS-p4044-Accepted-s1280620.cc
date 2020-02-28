#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int boss , n , sm = 0 , x;
    cin>>boss;
    cin>>n;
    vector <int> v(n , 0);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>v[i];
        sm += v[i];
    }
    sort(v.begin() , v.end());
    reverse(v.begin() , v.end());
    int ans = 1;

    for(int i = 0 ; boss <= sm ; i++)
    {
        boss += v[i];
        ans++;
        sm -= v[i];
    }
    cout<<ans<<"\n";
}

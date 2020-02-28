#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair <ll , ll > ii;

int freq[11111111];
const int sm = 1000001;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    vector <int> v;
    for(int i = 0 ; i < n ; i++)
    {
        int x;cin>>x;
        v.push_back(x);
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int tmp;
        cin>>tmp;
        ans = max(ans,++freq[tmp-v[i]+sm]);
    }
    cout<<ans<<"\n";
}

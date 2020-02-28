#include <bits/stdc++.h>

using namespace std;


#define db double
#define PB push_back
const int MAX = 1e5+5;



int n , k;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    vector <int>v(n , 0);
    for(int i = 0 ; i < n ; i++) cin>>v[i];
    sort(v.begin() , v.end());
    int cnt = 0;int ans = 0;
    for(int i = 0 ; i < n ; i++){
        cnt = 0;
        for(int j = i ; j < n ; j++)
            if(v[j]-v[i] <= k) cnt++;
        ans = max(ans , cnt);
    }
    cout<<ans<<"\n";
}
